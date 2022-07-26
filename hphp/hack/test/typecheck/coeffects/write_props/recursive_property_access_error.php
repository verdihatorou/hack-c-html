<?hh

class Bar {

  public function __construct(
    public bool $prop_bool,
  ) {}
}

class Foo {

  public function __construct(
    public Bar $prop_bar,
   ) {}

}

function pure_function(Foo $x)[] : void {
  $x->prop_bar->prop_bool = false; // Error
}

function write_props_function(Foo $x)[write_props] : void {
  $x->prop_bar->prop_bool = false; // No error
}
