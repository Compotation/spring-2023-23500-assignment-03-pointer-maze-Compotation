#include "Labyrinth.h"

bool isPathToFreedom(MazeCell *start, const std::string &moves) {
  return isPathToFreedom(start, moves, false, false, false);
}

bool isPathToFreedom(MazeCell *start, const std::string &moves, bool gotSpellbook, bool gotPotion, bool gotWand) {
  if (moves.empty()) {
    // need this because only previous position checked
    switch (start->whatsHere) {
      case Item::SPELLBOOK:
        gotSpellbook = true;
        break;
      case Item::POTION:
        gotPotion = true;
        break;
      case Item::WAND:
        gotWand = true;
        break;
      case Item::NOTHING:
        break;
    }
    return gotSpellbook && gotPotion && gotWand;
  }

   if (moves[0] == 'N' && start->north != nullptr) {
    switch (start->whatsHere) {
      case Item::SPELLBOOK:
        return isPathToFreedom(start->north, moves.substr(1), true, gotPotion, gotWand);
      case Item::POTION:
        return isPathToFreedom(start->north, moves.substr(1), gotSpellbook, true, gotWand);
      case Item::WAND:
        return isPathToFreedom(start->north, moves.substr(1), gotSpellbook, gotSpellbook, true);
      default:
        return isPathToFreedom(start->north, moves.substr(1), gotSpellbook, gotPotion, gotWand);
    }
  } else if (moves[0] == 'E' && start->east != nullptr) {
    switch (start->whatsHere) {
      case Item::SPELLBOOK:
        return isPathToFreedom(start->east, moves.substr(1), true, gotPotion, gotWand);
      case Item::POTION:
        return isPathToFreedom(start->east, moves.substr(1), gotSpellbook, true, gotWand);
      case Item::WAND:
        return isPathToFreedom(start->east, moves.substr(1), gotSpellbook, gotPotion, true);
      default:
        return isPathToFreedom(start->east, moves.substr(1), gotSpellbook, gotPotion, gotWand);
    }
  } else if (moves[0] == 'S' && start->south != nullptr) {
    switch (start->whatsHere) {
      case Item::SPELLBOOK:
        return isPathToFreedom(start->south, moves.substr(1), true, gotPotion, gotWand);
      case Item::POTION:
        return isPathToFreedom(start->south, moves.substr(1), gotSpellbook, true, gotWand);
      case Item::WAND:
        return isPathToFreedom(start->south, moves.substr(1), gotSpellbook, gotPotion, true);
      default:
        return isPathToFreedom(start->south, moves.substr(1), gotSpellbook, gotPotion, gotWand);
    }
  } else if (moves[0] == 'W' && start->west != nullptr) {
    switch (start->whatsHere) {
      case Item::SPELLBOOK:
        return isPathToFreedom(start->west, moves.substr(1), true, gotPotion, gotWand);
      case Item::POTION:
        return isPathToFreedom(start->west, moves.substr(1), gotSpellbook, true, gotWand);
      case Item::WAND:
        return isPathToFreedom(start->west, moves.substr(1), gotSpellbook, gotPotion, true);
      default:
        return isPathToFreedom(start->west, moves.substr(1), gotSpellbook, gotPotion, gotWand);
    }
  }

  // illegal move
  return false;
}