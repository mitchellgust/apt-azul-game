# Azul Game Implementation in  C++

### COSC 1076 - Advanced Programming Techniques

#### Project: 
- A two-player implementation of the Azul Board Game for CLI using C++14. (Developed: Oct 2020) 

#### View Report:
- [Summary of Our Implementation and Game Extentions 📚 ](https://github.com/s3782095/apt-azul-game/blob/e397764feca554d64397c92e7db55b5640e33ef8/RAM_Milestone4_APT.pdf)

#### Members: 
- Anh Nguyen (s3616128)
- Mitchell Gust (s3782095)
- Ruby Rio (s3786695)

#### Folder Structure
- *src*: store all source files
    - *bin*: store the program and all tests
    - *obj*: temporary folder to store object files

#### Running the application
- Require GNU Make
- Bash-compatible terminals only
- **Method 1: Automation**
    ```
    chmod +x run.sh (only need to do this once)
    ./run.sh (run the game normally)
    ./run.sh -t <filename> (engage test mode)
    ```
    
- **Method 2: Manual**
    ```
    cd src && sudo make && cd bin && ./azul && cd .. && cd ..
    ``` 
