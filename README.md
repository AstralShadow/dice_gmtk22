A game about dice

## The Game Jam
https://itch.io/jam/gmtk-jam-2022

## Building
You basicly want to do:

    git clone https://github.com/AstralShadow/dice_gmtk22
    cd dice_gmtk22
    mkdir build
    cd build
    cmake ..
    make -j$(nproc)
    ./dice

That would lead to nothing because this commit
contains only the engine.
