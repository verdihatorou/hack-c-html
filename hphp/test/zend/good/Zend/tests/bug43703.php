<?hh
class JoinPoint
{
}

abstract class Pointcut
{
    abstract public function evaluate(JoinPoint $joinPoint);
}

class Read extends Pointcut
{
    public function evaluate(JoinPoint $joinPoint)
    {
    }
}
<<__EntryPoint>> function main(): void {
echo "DONE";
}
