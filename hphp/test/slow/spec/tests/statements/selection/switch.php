<?hh

/*
   +-------------------------------------------------------------+
   | Copyright (c) 2015 Facebook, Inc. (http://www.facebook.com) |
   +-------------------------------------------------------------+
*/
<<__EntryPoint>> function main(): void {
error_reporting(-1);

$v = 10;

///*
switch ($v)
{
default: echo "default case: \$v is $v\n";
}

switch ($v)
{
case 20:
    echo "case 20\n";
    break;      // break ends "group" of case 20 statements
case 10:
    echo "case 10\n";   // no break, so control drops into next label's "group"
case 30:
    echo "case 30\n";   // no break, but then none is really needed either
}
//*/

///*
// Check duplicate case values: allowed; choses lexically first one

$v = 30;
switch ($v)
{
case 30:
    echo "case 30-2\n";
    break;
case 30:
    echo "case 30-1\n";
    break;
default:
    echo "default case: \$v is $v\n";
    break;
}

///*
// ; is allowed in place of : at end of case/default label; can mix-n-match

$v = 10;
switch ($v)
{
case 10;        // <================ ;
    echo "case 10\n";
    break;
case 20:        // <================ :
    echo "case 20\n";
    break;
default;        // <================ ;
    echo "default case: \$v is $v\n";
    break;
}
//*/

///*
// use  strings for label values

$v = "white";
switch ($v)
{
case "White":
    echo "case White\n";
    break;
case "Red":
    echo "case Red\n";
    break;
default:
    echo "default case: \$v is $v\n";
    break;
}

// use Booleans for label values

$v = TRUE;
switch ($v)
{
case FALSE:
    echo "case FALSE\n";
    break;
case TRUE:
    echo "case TRUE\n";
    break;
default:
    echo "default case: \$v is $v\n";
    break;
}
//*/

// use Booleans for label values

///*
$v = 22;
$a = 1;
$b = 12;
switch ($v)
{
case 10 + $b:
    echo "case 10 + $b\n";
    break;
case $v < $a:
    echo "case $v < $a\n";
    break;
default:
    echo "default case: \$v is $v\n";
    break;
}
//*/
}
