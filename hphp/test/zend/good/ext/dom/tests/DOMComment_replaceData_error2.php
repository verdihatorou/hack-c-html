<?hh
<<__EntryPoint>> function main(): void {
//offset to large
$dom = new DOMDocument();
$comment = $dom->createComment('test-comment');
try {
  $comment->replaceData(999,4,'-inserted');
} catch (DOMException $e ) {
  if ($e->getMessage() == 'Index Size Error'){
    echo "Throws DOMException for offest too large\n";
  }
}
}
