<?hh <<__EntryPoint>> function main(): void {
$xml = new XMLWriter();
$xml->openMemory();
$xml->setIndent(true);
$xml->startDocument();
$xml->startElement('test');
$xml->writeElement('foo', null);
$xml->writeElement('foo2', "");
$xml->writeElement('foo3');
$xml->startElement('bar');
try { $xml->endElement('bar'); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
$xml->endElement();
$xml->endElement();
print $xml->flush(true);

print "\n";

$xw = new XMLWriter();
$xw->openMemory();
$xw->setIndent(true);
$xw->startDocument();
$xw->startElementNS('test', 'test', 'urn:x-test:');
$xw->writeElementNS('test', 'foo', null, '');
$xw->writeElementNS(null, 'bar', 'urn:x-test:', '');
$xw->writeElementNS(null, 'bar', 'urn:x-test:', NULL);
$xw->writeElementNS(null, 'bar', 'urn:x-test:');
$xw->writeElementNS(null, 'bar', '', '');
$xw->endElement();
$xw->endDocument();
print $xw->flush(true);
}
