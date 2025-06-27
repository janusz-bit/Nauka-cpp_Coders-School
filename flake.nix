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

        BUILD_USE_NIX = "ON";
        name = "sdl-dev-shell";
        shellHook = ''
          echo "Welcome to the SDL development environment!"
          echo "You can start developing your SDL applications now."
        '';
        packages = with pkgs; [
          # Build tools
          cmake
          pkg-config
          gcc
          clang
          gnumake
          ninja

          # SDL dependencies
          xorg.libX11
          xorg.libXcursor
          xorg.libXext
          xorg.libXfixes
          xorg.libXi
          xorg.libXrandr
          sdl3

          alsa-lib
          dbus
          fcitx5
          libdecor
          libdrm
          libjack2
          libpulseaudio
          mesa # libgbm
          nas # libaudo
          pipewire
          sndio
          systemdLibs # libudev

          # SDL_VIDEODRIVER=wayland
          wayland
          libGL
          libffi
        ];
      };
    };
}
