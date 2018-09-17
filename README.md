# gzseek

Find gzip header (`1f 8b 08`) in the given file and print everything starting
with that header to standard output.

This little program is used in [mix-to-nix][] for finding a gzip archive in
concatenation of Mix package version, code archive, and metadata. We can only
carry that amalgamation out of Nix sandbox and not its separate parts.

However, it also has other uses, such as safely unpacking self-extracting gzip
archives. This will keep garbage that comes after the archive, but it doesn't
get in the way and allows to read more than one from a single file.

[mix-to-nix]: https://github.com/serokell/mix-to-nix
