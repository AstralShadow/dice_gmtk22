A bullet-hell game about luck and gambling

## Uploaded at itch.io
https://azcraft.itch.io/gamblers-odysee

## Submission for GMTK Game Jam
https://itch.io/jam/gmtk-jam-2022/rate/1617867

## Building (CMake)

    git clone https://github.com/AstralShadow/dice_gmtk22
    cd dice_gmtk22
    mkdir build
    cd build
    cmake ..
    make -j$(nproc)
    cp -r ../assets .
    ./gambler_odyssey

## Building (makefile)
Dependencies: SDL2 SDL2\_image

    git clone https://github.com/AstralShadow/dice_gmtk22
    cd dice_gmtk22
    make -j$(nproc)
    make run

Currently the game is still a beta version.
