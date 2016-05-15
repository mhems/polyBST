## Binary Search Tree implemented in several languages
---

A toy problem to experiment in a bunch of languages

Elements need to support:
* comparison with other objects
* represent themselves as strings

BST initially supports small API:
* parameterized comparator
* size() - number of elements in tree
* add(element) - adds an element to the tree
* contains(element) - true iff element in tree
* list() - return contents of tree in-order

Future additions to the API:
* iteration
* element removal

Each language's implementation is in a directory with the language's
name, which at a minimum has:
* src/
* tests/
* runtests.sh
* Makefile

This allows a language-agnostic way to compile (if needed) and run
tests. The language-agnostic mechanism may simply delegate to a
language-specific facility.

Ideally, tests are written indifferent to the implementation
language. The tests can then be translated to each implementation
language. This avoids tediously re-asserting the same API for each
language and allows API updates to propagate to each language's tests.

## TODO
---

* Start off with framework for language-generic tests
  - may need pseudo-DSL or templating system
  - create, compile, test, and generate script(s)
* Implement fluent languages: Java C C++ Python
* Implement familiar languages: Prolog Erlang Haskell Scheme
* Implement similar languages: C# D Go Rust Ruby OCaml
* Implement unfamiliar languages: Javascript Lua Nim Perl Smalltalk Swift
