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
  sf::SoundBuffer bruh_buffer;
  if (!bruh_buffer.loadFromFile("bruh_se.wav")){
    std::cout << "errore nel caricamento di qualche audio" << '\n';
  }
  sf::Sound bruh;
  bruh.setBuffer(bruh_buffer);
  


  //Creazione di finestra grafica
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
  window.setFramerateLimit(24);
  window.setKeyRepeatEnabled(false);

 
  while (window.isOpen()) {    
    
  //Disegno sfondo
  sf::Sprite sfondo;
  sfondo.setTexture(griglia);
  //sfondo.setOrigin(0., 0.);
  //sfondo.setPosition(0., 0.);
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
                        std::cout<<"megapalle"<<"\n";
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