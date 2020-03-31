#include "genius.h"

#include <QDebug>

Genius::Genius(QWidget* parent) : QWidget(parent)
{
  // Janela
  setFixedSize(static_cast<int>(screen()->geometry().width() * 0.22),
               static_cast<int>(screen()->geometry().height() * 0.4));

  // Vitoria/Derrota
  connect(this, SIGNAL(_passouDeNivel()), this, SLOT(iniciaNovoNivel()));
  connect(this, SIGNAL(_perdeuNoNivel()), this, SLOT(reiniciaJogo()));

  // UI
  criarLayoutDosBotoes();
  criarLayoutDoScore();
  _mainLayout = std::make_unique<QVBoxLayout>();
  _mainLayout->addWidget(_scoreBox.get());
  _mainLayout->addWidget(_gridGroupBox.get());
  setLayout(_mainLayout.get());

  // Som
  _som = std::make_unique<QSoundEffect>();
  _som->setLoopCount(1);
  _eventLoop = std::make_unique<QEventLoop>();
  connect(_som.get(), SIGNAL(playingChanged()), _eventLoop.get(),SLOT(quit()));
}

void Genius::iniciaNovoNivel()
{
  _scoreValor->setText(QString::number(_level));
  ++_level;
  _respostasDoJogador = 0;
  setStylesDosBotoes();
  _som->setSource(QUrl::fromLocalFile(":/sounds/nextLevel.wav"));
  _som->play();
  _eventLoop->exec();
  carregarDesafio();
  qDebug() << "Iniciando novo nivel...";
}

void Genius::reiniciaJogo()
{
  _som->setSource(QUrl::fromLocalFile(":/sounds/restart.wav"));
  _som->play();
  _eventLoop->exec();
  _scoreValor->setText(QString::number(0));
  _level = 1;
  _respostasDoJogador = 0;
  _jogoIniciado = false;
  qDebug() << "Jogo esta sendo reiniciado...";
}

void Genius::handleBotaoVerde()
{
  acaoDoButao(Color::verde);
  respostas.push_back(Color::verde);
  qDebug() << "Botao Verde clicado.";
  if (_jogoIniciado)
      checaVitoria();
}

void Genius::handleBotaoVermelho()
{
  acaoDoButao(Color::vermelho);
  respostas.push_back(Color::vermelho);
  qDebug() << "Botao Vermelho clicado.";
  if (_jogoIniciado)
      checaVitoria();
}

void Genius::handleBotaoAmarelo()
{
  acaoDoButao(Color::amarelo);
  respostas.push_back(Color::amarelo);
  qDebug() << "Botao Amarelo clicado.";
  if (_jogoIniciado)
      checaVitoria();
}

void Genius::handleBotaoAzul()
{
    acaoDoButao(Color::azul);
    respostas.push_back(Color::azul);
  qDebug() << "Botao Amarelo clicado.";
  if (_jogoIniciado)
      checaVitoria();
}

void Genius::handlBotaoIniciar()
{
  startGame();
  qDebug() << "Botao Iniciar clicado";
}

void Genius::criarLayoutDoScore()
{
  _scoreBox = std::make_unique<QGroupBox>();
  _scoreBox->setMaximumHeight(50);
  _scoreLayout = std::make_unique<QHBoxLayout>();

  _botaoStart = std::make_unique<QPushButton>("Iniciar");
  _scoreTitulo = std::make_unique<QLabel>("Desafios Concluidos: ");
  _scoreValor = std::make_unique<QLabel>("0");
  _scoreLayout->addWidget(_botaoStart.get(), 0, Qt::AlignLeft);
  _scoreLayout->addWidget(_scoreTitulo.get(), 0, Qt::AlignCenter);
  _scoreLayout->addWidget(_scoreValor.get(), 0, Qt::AlignCenter);
  _scoreBox->setLayout(_scoreLayout.get());

  // Adiciona evento de "ao soltar" no botao, chamar o call back handlBotaoIniciar()
  connect(_botaoStart.get(), SIGNAL(released()), this, SLOT(handlBotaoIniciar()));
}

void Genius::setStylesDosBotoes()
{
  _botaoVerde->setStyleSheet("background-color: green;");
  _botaoVermelho->setStyleSheet("background-color: red;");
  _botaoAzul->setStyleSheet("background-color: blue;");
  _botaoAmarelo->setStyleSheet("background-color: yellow;");
  // Atualiza na interface
  _botaoVerde->update();
  _botaoVermelho->update();
  _botaoAzul->update();
  _botaoAmarelo->update();
}

void Genius::criarLayoutDosBotoes()
{
  _gridGroupBox = std::make_unique<QGroupBox>();

  _gridLayout = std::make_unique<QGridLayout>();

  // Localizacao dos botoes
  _botaoVerde = std::make_unique<QPushButton>();
  _botaoVerde->setFixedSize(175, 175);
  _botaoVermelho = std::make_unique<QPushButton>();
  _botaoVermelho->setFixedSize(175, 175);
  _botaoAmarelo = std::make_unique<QPushButton>();
  _botaoAmarelo->setFixedSize(175, 175);
  _botaoAzul = std::make_unique<QPushButton>();
  _botaoAzul->setFixedSize(175, 175);
  setStylesDosBotoes();

  // Alinhar
  _gridLayout->addWidget(_botaoVerde.get(), 0, 0, 1, 1,
                          Qt::AlignRight | Qt::AlignBottom);
  _gridLayout->addWidget(_botaoVermelho.get(), 0, 1, 1, 1,
                          Qt::AlignLeft | Qt::AlignBottom);
  _gridLayout->addWidget(_botaoAmarelo.get(), 1, 0, 1, 1,
                          Qt::AlignRight | Qt::AlignTop);
  _gridLayout->addWidget(_botaoAzul.get(), 1, 1, 1, 1,
                          Qt::AlignLeft | Qt::AlignTop);

  _gridLayout->setColumnStretch(0, 10);
  _gridLayout->setColumnStretch(1, 10);
  _gridGroupBox->setLayout(_gridLayout.get());

  // Adiciona eventos nos botoes
  connect(_botaoVerde.get(), SIGNAL(released()), this, SLOT(handleBotaoVerde()));
  connect(_botaoVermelho.get(), SIGNAL(released()), this, SLOT(handleBotaoVermelho()));
  connect(_botaoAmarelo.get(), SIGNAL(released()), this, SLOT(handleBotaoAmarelo()));
  connect(_botaoAzul.get(), SIGNAL(released()), this,  SLOT(handleBotaoAzul()));
}

void Genius::acaoDoButao(Color color)
{
    switch(color)
    {
        case Color::verde:
            _som->setSource(QUrl::fromLocalFile(":/sounds/green.wav"));
            _som->play();
            _botaoVerde->setStyleSheet("background-color: white;");
            _eventLoop->exec();
            setStylesDosBotoes();
            break;
        case Color::vermelho:
            _som->setSource(QUrl::fromLocalFile(":/sounds/red.wav"));
            _som->play();
            _botaoVermelho->setStyleSheet("background-color: white;");
            _eventLoop->exec();
            setStylesDosBotoes();
            break;
        case Color::azul:
            _som->setSource(QUrl::fromLocalFile(":/sounds/blue.wav"));
            _som->play();
            _botaoAzul->setStyleSheet("background-color: white;");
            _eventLoop->exec();
            setStylesDosBotoes();
            break;
        case Color::amarelo:
            _som->setSource(QUrl::fromLocalFile(":/sounds/yellow.wav"));
            _som->play();
            _botaoAmarelo->setStyleSheet("background-color: white;");
            _eventLoop->exec();
            setStylesDosBotoes();
            break;
        default:
            break;
    }
}

void Genius::carregarDesafio()
{
  setStylesDosBotoes();
  respostas.clear();
  desafio.clear();
  for (int i = 0; i < _level; ++i)
  {
    int random = QRandomGenerator::global()->bounded(0, 4);
    acaoDoButao(Color(Color(random)));
    desafio.push_back(Color(random));
    // 500 ms de delay
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  // permite o player jogar
  _jogoIniciado = true;
}

void Genius::startGame()
{
    carregarDesafio();
}

void Genius::checaVitoria()
{
  if (respostas[_respostasDoJogador] == desafio[_respostasDoJogador])
  {
    if (respostas.size() == desafio.size())
        emit _passouDeNivel(); // Envia evento que passou de nivel
     else
        ++_respostasDoJogador;
  }
  else
      emit _perdeuNoNivel(); // Envia evento que perdeu o nivel
}
