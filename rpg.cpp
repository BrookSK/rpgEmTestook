#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// Fazer uma forma do personagem escolher suas raça

//teste on
//ok


struct Personagem{
    std::string nome;
    std::string armamento;
    unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demônio dominou as principais formas de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e não conseguimos nos defender\n";
    std::cout << "precisamos de alguém que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Você é nossa escolha!! E... a propósito... qual é mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){
    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia <<" de energia com uma forma de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaCidade(struct Personagem &p){ // &p referencia à struct "Personagem"
    
    unsigned int opcao = -1;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você está na rua principal da cidade, nesta rua você vê dois estabelecimentos: Uma quitanda de um lado uma loja de armas do outro.\n Para onde você deseja ir?" << std::endl;
        std::cout << "1-Quitanda\n2-Loja de armas" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-Que vá para a p*" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){
            
            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "Qual alimento desejas?" << std::endl;
                std::cout << "1-Macarrão (Dá muita energia)\n2-Balinha (Dá pouca energia) " << std::endl;

                std::cin >> opcao;

                switch(opcao){
                    case 1:
                        if(p.creditos >= 50){
                            p.energia += 50;
                            p.creditos -= 50;
                        }else{
                            std::cout << "Desculpe mas não dá..." << std::endl;
                        }
                        break;
                    case 2:
                        if(p.creditos >= 10){
                            p.energia += 10;
                            p.creditos -= 10;
                        }else{
                            std::cout << "Desculpe mas não dá..." << std::endl;
                        }
                        break;
                }

                return;
            }

        }else if(opcao == 3){
            std::cout << "Prepare-se para morrer indolente!!!" << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Que cara estranho....";
            return;
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te olha e pergunta: Pronto pra batalha?" << std::endl;
        
        std::cout << "1-Não\n2-Espada\n3-Adaga\n4-Arco e flecha" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            if(p.creditos >= 200){
                std::cout << "Bela escolha!" << std::endl;
                std::cout << "Muitos cairão por esta lámina!!" << std::endl;
                p.creditos = p.creditos - 200;
                p.armamento = "Espada";
                mostraStatusDoJogador(p);
            }else
                std::cout << "Você não merece este tesouro plebeu!!" << std::endl;
        }else if(opcao == 3){
            
            std::cout << "Pelo menos dá para apontar um lápis" << std::endl;

            if(p.creditos >= 25){
                std::cout << "ok..." << std::endl;
                p.creditos = p.creditos - 25;
                p.armamento = "Adaga";
                mostraStatusDoJogador(p);
            }else;
            
        }else if(opcao == 4){
            if(p.creditos >= 120){
                std::cout << "Saia daqui farrapo!!!" << std::endl;
                std::cout << "Uhm..." << std::endl;
                p.creditos = p.creditos - 120;
                p.armamento = "Arco e flecha";
                mostraStatusDoJogador(p);
            }else
                std::cout << "Saia daqui seu pobre!" << std::endl;
        }else{
            std::cout << "Vá embora!." << std::endl;
        }
    }
}

void faseTrapaceiros(struct Personagem &p){ // &p referencia à struct "Personagem"
        unsigned int opcao = -1;

        while(opcao < 1 || opcao > 2){
            std::cout << "Agora tu estás perambulando pelos campos e montanhas até que acidentalmente defronta-se com dois trapaceiros. Tu tens duas opções: " << std::endl;
            std::cout << "1-Indecisão\n2-Fujir" << std::endl;
            std::cin >> opcao;
        }

        if(opcao == 1){

            if(p.armamento == ""){
                std::cout << "Você vai na mão contra os trapaceiros..." << std::endl;
                p.creditos = p.creditos - p.creditos;
                std::cout << "Você foi roubado e agora possui " << p.creditos << " créditos" << std::endl;
            }else{
                std::cout << "Tu sacas vosso(a) " << p.armamento << " e intimida os trapaceiros" << std::endl;
                std::cout << "Eles não se intimidam e partem para cima. Tu tens a oportunidade de matá-los, o que tu farás?" << std::endl;
                std::cout << "1-Os Matarei\n2-Os Imobilizarei" << std::endl;
                std::cin >> opcao;
                if(opcao == 2){
                    
                    opcao = 0;

                    while(opcao < 1 || opcao > 2){
                        std::cout << "A partir de qual parte do corpo desejas tu imobilizar os dois trapaceiros?" << std::endl;
                        std::cout << "1-A partir da cabeça\n2-A partir das pernas" << std::endl;

                        std::cin >> opcao;

                        switch(opcao){
                            case 1:
                                if(p.creditos >= 30){
                                    p.energia -= 70;
                                    p.creditos -= 20;
                                }else{
                                    std::cout << "Desculpe, mas não dá..." << std::endl;
                                }
                                break;
                            case 2:
                                if(p.creditos >= 15){
                                    p.energia += 50;
                                    p.creditos -= 10;
                                }else{
                                    std::cout << "Desculpe, mas não dá..." << std::endl;
                                }
                                break;
                            default:
                                std::cout << "Erro" << std::endl;
                                break;
                        }

                        return;
                    }

                }else if(opcao == 1){
                    std::cout << "Preparem-se para morrerem, indolentes!!!" << std::endl;
                    p.energia = p.energia - p.energia;
                    std::cout << "Eles morrem e tu continuas vosso caminho..." << std::endl;
                    return;
                }else{
                    std::cout << "Não farás nada? (...)";
                    return;
                }
        
        }if(opcao == 2){
            std::cout << "Você então decidiu fujir? foi um erro!" << std::endl;
            std::cout << "Você infelizmente tropeça e é capturado pelos dois trapaceiros. O que farás agora?" << std::endl;
            
            std::cout << "1-Pedir redenção\n2-Escapar\n3-Tentar matá-los" << std::endl;
            std::cin >> opcao;

            if(opcao == 1){

                std::cout << "Eles nunca lhe darão redenção!" << std::endl;

            }else if(opcao == 2){
                
                std::cout << "Impossível! Você está preso!" << std::endl;
            
            }else if(opcao == 3){
                std::cout << "Você sorrateiramente puxa uma faquinha escondida em suas vestes, infelizmente um trapaceiro percebe e te nocauteia" << std::endl;

                if(p.creditos >= 60){
                    std::cout << "Você perdeu 60 pontos de energia!..." << std::endl;
                    p.energia = p.energia - 60;

                    mostraStatusDoJogador(p);
                }else{
                    std::cout << "Você infelizmente morreu!!!" << std::endl;
                }
            }else{
                std::cout << "Não fará nada?" << std::endl;
            }
        } 
    }
}


int main(int argc, char** argv)
{
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);
    faseDaCidade(j);
    faseTrapaceiros(j);

    mostraStatusDoJogador(j);
}
