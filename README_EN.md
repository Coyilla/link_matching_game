
# LianLianKan Game (Match-3 Puzzle)

A classic match-3 puzzle game developed using C++ and EasyX graphics library, featuring rich graphical interface and complete game functionality.

## 中文版本
[click here](./lanlankan1/README.md)
## Project Overview

This is a fully functional match-3 puzzle game that supports multiple game modes, leaderboard system, sound effects, and beautiful graphical interface. The game uses EasyX graphics library for interface rendering, providing a smooth gaming experience.

## Project Detailed Design Documentation
 View here [Design Documentation](./lanlankan1/程序设计课程实践课程大作业_连连看实验报告.doc)

## Features

### 🎮 Game Features
- **Three Difficulty Modes**: Easy (10×10), Medium (12×12), Hard (14×14)
- **Time Limit**: 250-second countdown timer for added challenge
- **Smart Connection Algorithm**: Supports straight lines, one corner, and two corners connections
- **Sound System**: Background music and elimination sound effects
- **Pause/Resume**: Can pause the game at any time during gameplay

### 🏆 Leaderboard System
- Automatically records player scores
- Score-based ranking system
- Supports viewing rankings for different difficulty modes
- Records player name, score, time used, and game time

### 🎨 Graphical Interface
- Beautiful background images and icons
- Mouse hover magnification effect
- Chinese interface and prompt information
- Responsive button design

## Technology Stack

- **Programming Language**: C++
- **Graphics Library**: EasyX (for Windows graphical interface development)
- **Multimedia**: Windows Multimedia API (sound effects playback)
- **File Operations**: Standard C file I/O (leaderboard data storage)

## Project Structure

```
lanlankan1/
├── main.cpp              # Main program file containing all game logic
├── lanlankan1.vcxproj    # Visual Studio project file
├── Various image resource files  # Backgrounds, icons, buttons, etc.
├── Sound effect files    # Game sound effects
└── Leaderboard data files # Text files storing player scores
```

## Compilation and Running

### Environment Requirements
- Windows operating system
- Visual Studio (recommended)
- EasyX graphics library

### Compilation Steps
1. Install EasyX graphics library
2. Open `lanlankan1.vcxproj` project file in Visual Studio
3. Compile and run the project

### Direct Execution
If you already have the compiled executable:
```bash
lanlankan1.exe
```

## Game Operation Guide

1. **Start Game**: Click "Start" button and enter player name
2. **Select Difficulty**: Choose game difficulty in the start interface
3. **Game Operation**:
   - Click two identical icons to eliminate them
   - Icons can be connected via straight lines or up to two corners
   - Use "Pause" button to pause the game
4. **View Leaderboard**: Click "Leaderboard" button to check scores
5. **About Information**: Click "About" button for game information

## Game Rules

- Eliminate all icons within the time limit to win
- Score calculation: Remaining time × 50 + Eliminated icons × 25
- Game ends when time runs out or no more moves are possible

## File Description

- `player_rank1_little.txt`: Easy mode leaderboard data
- `player_rank1_medium.txt`: Medium mode leaderboard data
- `player_rank1_large.txt`: Hard mode leaderboard data
- Various PNG images: Game interface elements
- WMA/MP3 files: Game sound effects

## Development Information

### Main Data Structures
```c++
struct Player {
    char name[20];     // Player name
    int score;        // Score
    int n;            // Game scale (difficulty)
    double time;      // Time used
    int rank;         // Ranking
    int remain;        // Remaining icons
    char date[20];    // Game time
};

struct Index {
    int x, y;         // Coordinate index
};
```

### Core Algorithms
- Map generation and shuffling algorithm
- Connection detection algorithm (straight line, corner detection)
- Leaderboard sorting and storage algorithm
- Graphics rendering and mouse interaction processing

## Notes

1. Ensure all resource files (.png, .wma, .mp3) are in the same directory as the executable
2. Game requires EasyX graphics library support
3. Leaderboard files are automatically created and updated

## Author

Hou Junjie - Yijue Gaoxia (Easy Version)

## License

This project is for learning and entertainment purposes only.

        