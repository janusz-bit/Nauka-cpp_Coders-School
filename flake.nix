{
  description = "SDL Project Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        
        name = "sdl-dev-shell";
        shellHook = ''
          echo "Welcome to the SDL development environment!"
          echo "You can start developing your SDL applications now."
          export PS1="\[\e[91m\]nix develop:\[\e[0m\] $PS1"
        '';
        packages = with pkgs; [
          # Build tools
          cmake
          pkg-config
          gcc
          clang
          gnumake
          ninja
          sdl3
        ];
      };
    };
}
