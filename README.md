# Cricket Match Simulator

This project is a Cricket Match Simulator developed in C++ as part of the **Programming Fundamentals** course. It simulates a cricket match between two teams using **1D, 2D, and 3D arrays** and employs random functions to generate match events such as runs, wickets, and toss results. 

## Features
- **Team Formation**: Two teams of 11 players each, with attributes like runs scored, balls faced, wickets taken, etc.
- **Match Configuration**: Reads number of overs from a `configuration.txt` file.
- **Toss Simulation**: Randomized toss to decide which team bats first.
- **Scoreboard Display**: Dynamic and real-time scoreboard updates.
- **Realistic Batting and Bowling Mechanics**:
  - Probability-based scoring for batsmen and bowlers.
  - Player-specific chances of getting out.
- **Bowling Rules**:
  - Last five players of the bowling team act as bowlers.
  - Each bowler can bowl up to `total_overs/5` overs.
- **Match Flow**:
  - Players bat and bowl according to pre-defined probabilities.
  - Live scorecard updates after each ball.
  - Players get out randomly, and the match progresses accordingly.
- **Match Control**:
  - Ball bowled by pressing `ENTER`.
  - Option to **jump to any over** during the innings.
  - Optional short delay after each ball for better visualization.
- **Innings Handling**:
  - Full scoreboard displayed at the end of the first innings.
  - Second innings includes **target, remaining overs, required run rate**.
- **Post-Match Summary**:
  - Winning team declared.
  - **Bowler of the Match** (highest wickets taken).
  - **Batsman of the Match** (highest runs scored).
  - Option to **save match data to a file**.
  - Load and view previous match data from file.

## Technical Details
- Implemented in **C++**.
- Uses **dynamic memory allocation** for better memory management.
- File handling for reading configuration and storing match results.
- Extensive use of **functions** for modularity and reusability.
- **Switch case menu system** for post-match functionalities.

## How to Run the Project
1. **Compile the C++ source file** using a C++ compiler (e.g., g++ for GCC):
   ```bash
   g++ cricket_match_simulator.cpp -o cricket_simulator
   ```
2. **Run the executable**:
   ```bash
   ./cricket_simulator
   ```
   
## File Structure
```
|-- cricket_match_simulator.cpp  # Main program file
|-- configuration.txt            # Stores match settings (number of overs)
|-- match_data.txt               # Stores match summaries for future reference
|-- README.md                    # Project documentation
```

## Requirements
- **C++ Compiler**
- **Basic knowledge of C++** and file handling

## Notes
- **Global variables are NOT used**.

## Author
**Zaib Un Nisa**
Programming Fundamentals [Spring 2022]

