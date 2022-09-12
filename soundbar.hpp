#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

void soundbar() {

  std::vector<double> vector{0., 125., 250., 375., 500., 625., 750., 875.};

  //Acquisizione sfondo 
  sf::Texture griglia;
  if (!griglia.loadFromFile("griglia.png")) {
    std::cout << "errore nel caricamento immagine!" << '\n';
  }


  //Acquisizione e creazione audio
  //1,1
  sf::SoundBuffer bruh_buffer;
  if (!bruh_buffer.loadFromFile("sounds/bruh_se.wav")){
    std::cout << "errore nel caricamento di bruh" << '\n';
  }
  sf::Sound bruh;
  bruh.setBuffer(bruh_buffer);

  //2,1
  sf::SoundBuffer saul_buffer;
  if (!saul_buffer.loadFromFile("sounds/saul_se.ogg")){
    std::cout << "errore nel caricamento di saul" << '\n';
  }
  sf::Sound saul;
  saul.setBuffer(saul_buffer);

  //3,1
  sf::SoundBuffer pussy_buffer;
  if (!pussy_buffer.loadFromFile("sounds/pussy_se.ogg")){
    std::cout << "errore nel caricamento di pussy" << '\n';
  }
  sf::Sound pussy;
  pussy.setBuffer(pussy_buffer);

  //4,1
  sf::SoundBuffer dog_doing_buffer;
  if (!dog_doing_buffer.loadFromFile("sounds/dog_doing_se.ogg")){
    std::cout << "errore nel caricamento di dog_doing" << '\n';
  }
  sf::Sound dog_doing;
  dog_doing.setBuffer(dog_doing_buffer);

  //5,1
  sf::SoundBuffer gangsta_buffer;
  if (!gangsta_buffer.loadFromFile("sounds/gangsta_se.ogg")){
    std::cout << "errore nel caricamento di gangsta" << '\n';
  }
  sf::Sound gangsta;
  gangsta.setBuffer(gangsta_buffer);

  //6,1
  sf::SoundBuffer boom_buffer;
  if (!boom_buffer.loadFromFile("sounds/boom_se.ogg")){
    std::cout << "errore nel caricamento di boom" << '\n';
  }
  sf::Sound boom;
  boom.setBuffer(boom_buffer);

  //7,1
  sf::SoundBuffer augh_buffer;
  if (!augh_buffer.loadFromFile("sounds/augh_se.ogg")){
    std::cout << "errore nel caricamento di augh" << '\n';
  }
  sf::Sound augh;
  augh.setBuffer(augh_buffer);

  //8,1
  sf::SoundBuffer healing_buffer;
  if (!healing_buffer.loadFromFile("sounds/healing_se.ogg")){
    std::cout << "errore nel caricamento di healing" << '\n';
  }
  sf::Sound healing;
  healing.setBuffer(healing_buffer);
  



  //Creazione di finestra grafica
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
  window.setFramerateLimit(24);
  window.setKeyRepeatEnabled(false);

 
  while (window.isOpen()) {    
    
  //Disegno sfondo
  sf::Sprite sfondo;
  sfondo.setTexture(griglia);
  window.clear(sf::Color::Blue);
  window.draw(sfondo);
  window.display();
  
    
    sf::Event event;

    while (window.pollEvent(event)) {  //While di gestione eventi

      switch (event.type) {  //Controllo tipo evento

        case sf::Event::Closed:  //Chiusura finestra
          window.close();
          break;





        //OK DA QUI SI MUORE
        case sf::Event::MouseButtonPressed:  //SOUND
          if (event.mouseButton.button == sf::Mouse::Left) {
            
            double x = static_cast<double>(event.mouseButton.x);
            double y = static_cast<double>(event.mouseButton.y);

            int pos_x = 0;
            int pos_y = 0;

            for (double const& check_x : vector){
            if (x > check_x){++pos_x;}
            if (y > check_x){++pos_y;}
            }

            switch (pos_y){

            //RIGA 1
            case 1:
                    switch (pos_x)
                    {
                    case 1:
                        bruh.play();
                        break;

                    case 2:
                        saul.play();
                        break;

                    case 3:
                        pussy.play();
                        break;

                    case 4:
                        dog_doing.play();
                        break;

                    case 5:
                        gangsta.play();
                        break;
                        
                    case 6:
                        boom.play();
                        break;

                    case 7:
                        augh.play();
                        break;

                    case 8:
                        healing.play();
                        break;

                    default:
                        break;
                    }
        
                break;
            /*
            //COLONNA 2
            case 2:
                    switch (pos_x)
                    {
                    case 1:
                        bruh.play();
                        break;
            
                    default:
                        break;
                    }
        
                break;
            */








            default:
                break;
            }


        }//Chiusura if click sinistro
          break;


            default:
            break;
      }//Chiusura switch principale

    }//Chiusura while eventi

  }
}