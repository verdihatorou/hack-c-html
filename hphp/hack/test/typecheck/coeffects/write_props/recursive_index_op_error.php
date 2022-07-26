<?hh

class Foo {

  public function __construct(
    public dict<string, dict<string, string>> $prop_nested_dict,
   ) {}

}

function pure_function(Foo $x)[] : void {
  $x->prop_nested_dict['a']['a'] = 'b'; // Error
}

function write_props_function(Foo $x)[write_props] : void {
  $x->prop_nested_dict['a']['a'] = 'b'; // No error
}
