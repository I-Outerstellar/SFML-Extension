# Lets make SFML for the one purpose of my slider game!

Yea uh the github repo name is misleading. I just wanted to make a framework over SFML for my one project I'm doing. I'll make an actual SFML extension some other time.

That said, it has actually turned into a project that can support multiple types of simple game projects. I'll write what it is capable of.



# Framework Details

- Many game objects and controllers to control one global window, the only window that should be used

- Button support

- Scenes to switch between

- Z-Index of buttons and shapes that can be changed mid-execution

- Supports inheritence of game shapes and buttons



# Limitations

- Does not have a built-in way to size shapes relative to the screen size

- Buttons always draw over shapes

- Z-Indexes of shapes and buttons cannot be different between multiple scenes

- Cannot make a derived class from GameScene, unless you are only changing a method's behaviour instead of adding a new attribute/method. Please use its properties map instead to achieve similar behaviour.

- Works alongside SFML methods rather than using new, original ones (this project was not made to reinvent the wheel)

