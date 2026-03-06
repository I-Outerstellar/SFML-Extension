# Lets make SFML for the one purpose of my slider game!

Yea uh the github repo name is misleading. I just wanted to make a framework over SFML for my one project I'm doing. I'll make an actual SFML extension some other time.

That said, it has actually turned into a project that can support multiple types of simple game projects. I'll write what it is capable of.



# Framework Details

- Many game objects and controllers to control one global window, the only window that should be used

- Button support

- Scenes to switch between

- Z-Index of buttons and shapes

- Supports inheritence of game shapes and buttons



# Limitations

- Cannot change the Z-Index of buttons and shapes

- Buttons always draw over shapes

- Cannot make a derived class from GameScene. Please use its properties map instead to achieve similar behaviour.

- Works alongside SFML methods (this project was not made to reinvent the wheel)



# Future Plans

- Support of sprites and sprite buttons

- Putting all the .hpp and .cpp files into folders

- Any necessary cleanup