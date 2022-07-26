<?hh

class Ref {
  function __construct(public $value)[] {}
}

async function noblock() {
  echo "not blocking\n";
}

async function block() {
  echo "block enter\n";
  await RescheduleWaitHandle::create(RescheduleWaitHandle::QUEUE_DEFAULT, 0);
  echo "block exit\n";
}

async function block_then_succeed(Ref $condition) {
  echo "block enter\n";
  await RescheduleWaitHandle::create(RescheduleWaitHandle::QUEUE_DEFAULT, 0);
  echo "block exit\n";
  $condition->value->succeed(42);
}

async function block_then_fail(Ref $condition) {
  echo "block enter\n";
  await RescheduleWaitHandle::create(RescheduleWaitHandle::QUEUE_DEFAULT, 0);
  echo "block exit\n";
  $condition->value->fail(new Exception('horrible failure'));
}
<<__DynamicallyCallable>>
async function condition_noblock() {
  $condition = ConditionWaitHandle::create(noblock());
  echo "not reached\n";
}
<<__DynamicallyCallable>>
async function condition_block() {
  $condition = ConditionWaitHandle::create(block());
  echo "constructed ConditionWaitHandle\n";
  await $condition;
  echo "not reached\n";
}
<<__DynamicallyCallable>>
async function condition_block_ugly_succeed() {
  $condition = ConditionWaitHandle::create(block());
  echo "constructed ConditionWaitHandle\n";
  $condition->succeed(42);
  return await $condition;
}
<<__DynamicallyCallable>>
async function condition_block_ugly_fail() {
  $condition = ConditionWaitHandle::create(block());
  echo "constructed ConditionWaitHandle\n";
  $condition->fail(new Exception('horrible failure'));
  return await $condition;
}
<<__DynamicallyCallable>>
async function condition_block_nice_succeed() {
  $condition = new Ref(null);
  $condition->value = ConditionWaitHandle::create(
    block_then_succeed($condition)
  );
  echo "constructed ConditionWaitHandle\n";
  return await $condition->value;
}
<<__DynamicallyCallable>>
async function condition_block_nice_fail() {
  $condition = new Ref(null);
  $condition->value = ConditionWaitHandle::create(block_then_fail($condition));
  echo "constructed ConditionWaitHandle\n";
  return await $condition->value;
}

async function run_one(string $name) {
  try {
    echo "running $name...\n";
    $res = await $name();
    echo "succeeded: $res\n";
  } catch (Exception $e) {
    echo "failed: {$e->getMessage()}\n";
  }
  await RescheduleWaitHandle::create(RescheduleWaitHandle::QUEUE_DEFAULT, 1);
  echo "\n";
}

async function run() {
  await run_one('condition_noblock');
  await run_one('condition_block');
  await run_one('condition_block_ugly_succeed');
  await run_one('condition_block_ugly_fail');
  await run_one('condition_block_nice_succeed');
  await run_one('condition_block_nice_fail');
}


<<__EntryPoint>>
function main_condition() {
HH\Asio\join(run());
}
