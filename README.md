# EndlessBattle

## Description
This is a text interface game in which players spawn and are immediately faced with an unending series of battles. Each battle is turn based and involves two combatants, the player and a CPU opponent. There is no way to "beat" the game; high scores are represented by the number of opponents defeated in a row before a player loses all health points. During each battle, a player has four options:
  1) Fight using 4 preset moves.
  2) Use healing abilities on oneself.
  3) Randomly obtain 1 item that will be placed in the bag (examples include healing items, attack boost items, useless dummy items, and powerful bomb items). 
  4) Use an item that is in the bag.
When a player selects their move, they will always execute first, and the CPU will always execute afterwards. The CPU has no access to items, and can only attack using 4 preset moves or use healing abilities on itself. When the CPU opponent is defeated, a new one will immediately spawn. Each CPU opponent will have a random quantity of health points greater than 50% but no greater than 200% of the player's starting health point total. Attack power is randomized with certain moves having a larger range of damage with others having a smaller range of damage, thereby making some attacks high-risk, high-reward. The player and the CPU will have the same attacks with the same base power, meaning that the player will generally be outmatched when their opponent spawns with greater hp than themselves, but will have the advantage when the opponent spawns with less hp than themselves. Items will serve as the equalizer when players are fighting opponents with greater hp totals than themselves, with certain rare items having the ability to dispatch opponents immediately. When the player loses all health points, the game ends, and the total number of defeated opponents represents their high score.   
## Design
Datatypes:
string - playername - player's name
int - playerhealth - User's hp total
int - enemyhealth - CPU's hp total
int - attackpower - attack power of moves
int - healpower - healing power of abilities
int - item - type of item that player obtains
int - score - number of opponenets defeated by player (final highscore)
int - itemheal - healing power of items
int

## Authors
 - Harris
 - 

