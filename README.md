# Dead Man Draw - Card Game

A C++ implementation of the Dead Man Draw card game, featuring object-oriented design patterns and a robust architecture for card game mechanics.

## Table of Contents

- [Overview](#overview)
- [Game Rules](#game-rules)
- [Features](#features)
- [Architecture](#architecture)
- [Design Decisions](#design-decisions)
- [Running](#running)
- [Future Enhancements](#future-enhancements)

## Overview

Dead Man Draw is a strategic card game where players must carefully balance risk and reward. Players draw cards to accumulate points, but drawing two cards of the same type ends their turn and forfeits their points. The game demonstrates advanced C++ concepts including inheritance, templates, factory patterns, and the singleton pattern.

## Game Rules

1. **Objective**: Accumulate the highest score by strategically drawing cards
2. **Turn Structure**:
   - Players draw cards one at a time from the deck
   - Each card has a point value and special ability
   - Players can choose to "bank" their current points or continue drawing
3. **Bust Rule**: Drawing two cards of the same type ends your turn immediately and you lose all unbanked points
4. **Special Abilities**: Each card type has unique abilities that can affect gameplay
5. **Winning**: The player with the highest banked score when the deck is empty wins

## Features

- **Multiple Card Types**: Each with unique point values and special abilities
- **Strategic Gameplay**: Risk management between banking points and drawing more cards
- **Flexible Architecture**: Easy to add new card types and game mechanics
- **Type-Safe Containers**: Template-based container system for managing cards
- **Centralized Game State**: Singleton pattern ensures consistent game state management

## Architecture

The game is built on several key architectural decisions:

### 1. **Card Hierarchy (Inheritance)**
- Base `Card` class with virtual `play()` method
- Specialized subclasses for each card type (e.g., Cannon, Mermaid, Sword, etc.)
- Each card type implements its own unique ability
- Follows the **Open/Closed Principle**: Open for extension, closed for modification

### 2. **Container System (Templates)**
- Abstract `CardContainer<T>` template class defines common interface
- Two implementations:
  - `VectorContainer`: Sequential access for Deck, DiscardPile, PlayArea
  - `MapContainer`: Key-based access for Bank (quick card type lookup)
- Provides flexibility while maintaining type safety

### 3. **Card Creation (Factory Pattern)**
- `CardFactory` class with static factory methods
- Centralizes all card creation logic
- Simplifies adding new card types
- Encapsulates card initialization details

### 4. **Game Management (Singleton Pattern)**
- `Game` class ensures single game instance
- Manages game state, flow, and components
- Provides global access point for game operations
- Prevents inconsistent state from multiple instances

### Card Types

Each card type inherits from `Card` and implements unique abilities:

- **Cannon**: Steals points from opponents
- **Mermaid**: Allows peeking at next card
- **Sword**: Protects against certain card effects
- **Chest**: Bonus points when banked
- **Kraken**: High risk, high reward card
- **Hook**: Retrieves cards from discard pile
- **Map**: Reveals upcoming cards
- **Oracle**: Predicts future draws


## Design Decisions

### Why Inheritance for Cards?
- Each card type has unique behavior (ability)
- Easy to add new card types without modifying existing code
- Polymorphism allows treating all cards uniformly while maintaining specific behaviors
- Supports Open/Closed Principle

### Why Templates for Containers?
- Type safety at compile time
- Code reuse across different container types
- Flexibility to use different underlying data structures (vector vs map)
- Performance optimization based on access patterns

### Why Static Factory Methods?
- Card objects are immutable after creation
- Centralizes creation logic
- Simplifies adding new card types
- Avoids complex constructor overloading

### Why Singleton for Game?
- Ensures single source of truth for game state
- Prevents inconsistent state from multiple game instances
- Simplifies access to game components
- Global access point for players and cards

# Running
Navigate to x64/Release and run DeadMansDraw.exe

## Future Enhancements

- [ ] Add multiplayer support (2-4 players)
- [ ] Implement AI opponents with different difficulty levels
- [ ] Add graphical user interface (GUI)
- [ ] Save/load game state functionality
- [ ] Network multiplayer support
- [ ] Additional card types and abilities
- [ ] Statistics tracking and leaderboards
- [ ] Sound effects and animations

## Contributing

Contributions are welcome! Please follow these guidelines:

1. Fork the repository
2. Create a feature branch 
3. Commit your changes 

## Acknowledgments

- Inspired by the original Dead Man Draw mobile game
- Built as a demonstration of object-oriented design patterns in C++
- System design follows SOLID principles and best practices

---

