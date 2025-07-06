{
  description = "SDL Project Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    {
      self,
      nixpkgs,
      ...
    }@inputs:
    let
      linux = "x86_64-linux";
      pkgs = import nixpkgs {
        system = linux;
        config.allowUnfree = true;
      };
    in
    {
      devShells.${linux}.default = pkgs.mkShell {

        name = "sdl-dev-shell";
        shellHook = ''
          echo "Welcome to the development environment!"
        '';
        buildInputs = with pkgs; [
          cmake
          pkg-config
          gcc
          clang-tools
          gnumake
          ninja
          sdl3
        ];
      };

    };
}
