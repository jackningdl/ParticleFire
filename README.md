# ParticleFire

A 1024 * 800 window simulating fire work, practicing SDL and C++.

## CMakeList

MacOS is different from Linux system and should avoid unexpected mistakes.

Using `find` instead of using `set`.

```
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(SDL_Basic main.cpp)
target_link_libraries(SDL_Basic ${SDL2_LIBRARIES})
```

### Bit shifting

```C++
unsigned char alpha = 0xFF
unsigned char red = 0x12
unsigned char blue = 0x34
unsigned char green = 0x56

// color --> 000000ff
color = color << 8;
// color --> 0000ff00
cout << setfill('0') << setw(8) << hex << color << endl;

```