#ifndef Genius_H
#define Genius_H

#include <QEventLoop>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QScreen>
#include <QWidget>
#include <QtMultimedia/QSoundEffect>
#include <chrono>
#include <memory>
#include <thread>
#include <vector>
#include <QRandomGenerator>

class Genius : public QWidget
{

 Q_OBJECT
 public:
  explicit Genius(QWidget *parent = nullptr);
  virtual ~Genius() = default;

  Q_INVOKABLE void startGame();

  enum class Color { verde, vermelho, amarelo, azul };

 private:

  // Grids
  std::unique_ptr<QGroupBox> _scoreBox;
  std::unique_ptr<QGridLayout> _gridLayout;
  std::unique_ptr<QHBoxLayout> _scoreLayout;
  std::unique_ptr<QGroupBox> _gridGroupBox;
  std::unique_ptr<QVBoxLayout> _mainLayout;
  // Botoes
  std::unique_ptr<QPushButton> _botaoVerde;
  std::unique_ptr<QPushButton> _botaoVermelho;
  std::unique_ptr<QPushButton> _botaoAmarelo;
  std::unique_ptr<QPushButton> _botaoAzul;
  std::unique_ptr<QPushButton> _botaoStart;
  // UI
  std::unique_ptr<QWidget> _janela;
  std::unique_ptr<QLabel> _scoreTitulo;
  std::unique_ptr<QLabel> _scoreValor;
  // Efeitos
  std::unique_ptr<QSoundEffect> _som;
  std::unique_ptr<QEventLoop> _eventLoop;
  // Logica
  std::vector<Color> desafio;
  std::vector<Color> respostas;
  // Helpers
  inline static int _level = 1;
  inline static int _respostasDoJogador = 0;
  inline static bool _jogoIniciado = false;

  // Funcoes
  void criarLayoutDosBotoes();
  void criarLayoutDoScore();
  void carregarDesafio();
  void acaoDoButao(Color color);
  void checaVitoria();
  void setStylesDosBotoes();

  // Handlers dos eventos (callbacks)
 private slots:
  void handleBotaoVerde();
  void handleBotaoVermelho();
  void handleBotaoAmarelo();
  void handleBotaoAzul();
  void handlBotaoIniciar();
  void iniciaNovoNivel();
  void reiniciaJogo();

  // Sinais (desperadores de eventos)
 signals:
  void _passouDeNivel();
  void _perdeuNoNivel();
};

#endif  // Genius_H
