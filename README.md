# ct4102-unreal-mechanics-brandon-toews
ct4102-unreal-mechanics-brandon-toews created by GitHub Classroom

## Programming and Algorithms Unreal Project
**Name:** Brandon Toews

C# Scripts are located in the [Source/UnrealMechanics](Source/UnrealMechanics) folder of this repo.

### 🚀 Play [Demo](https://brandon-toews.github.io/prog-design-patterns.app/)
(Had to compile demo to WASM using Unreal Engine 4.28 built from source so the shaders didn't turn out right)

**Player Controls:** \
W - Forward \
S - Backward \
A - Strafe Left \
D - Strafe Right

Mouse - Look Around

Space Bar - Jump \
Right/Left Shift - Run \
Left Mouse Button - Fire Bullet

Esc - Quit Game

## Game Programming Design Mechanics
### 1. Command Design Pattern (C++)
Created C++ classes that inherit from UObject class. Three command child classes(Jump, Run and Fire) inherit from a base command class. Command objects   are created by the level blueprint based on keyboard and mouse inputs. These command objects then go on to execute the specific command they were         designed for.

### 2. State Machine Design Pattern (C++)
Created C++ state classes are that inherit from UObject class and are managed by a StateManager class that inherits from Actor component class. The StateManager actor component object is created and attached to the enemy character class. The StateManager component then creates the three different state objects, switches the current state based on certain conditions and runs the current state.

### 3. Object Pool Design Pattern (Blueprints)
Created Blueprint BulletPool class actor component that attaches to actors and created a set number of bullets from the blueprint bullet class. The bulletpool than attaches the created bullets to the character and when the chsaracter's fire method is invoked it uses the bullets from the bullet pool. If the bullet pool becomes empty then the player must wait for it to refill before firing more bullets.

### 4. Prototype Design Pattern (Blueprints)
Created Blueprint spawn classes that spawn different enemy characters from blueprint child enemy character classes.

One type of spawn class has a public variable that can be set in the unreal inspector for each instance that stores a specific enemy character class.  It then spawns a character based on the saved enemy character class and saves it and continues to invoke that intial spawned character's Clone method to spawn more characters of that class. This spawner creates and stores only one prototype of one type of enemy to spawn further enemies from.

The other type of spawn class stores all of the different enemy classes. It randomly selects an enemy class from the list of enemy classes, spawns an instance of this class, runs the Clone method of that instance to spawn an enemy, and finally destroys the initial instance of the enemy. So  this spawner type can spawn any type of enemy by creating and using a prototype of that enemy.
