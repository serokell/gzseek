with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "gzseek";
  src = lib.cleanSource ./.;

  nativeBuildInputs = [ meson ninja pkgconfig ];
  buildInputs = [ glib ];
}
