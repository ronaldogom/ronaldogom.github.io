%% RNA-MLP - Aproximação de uma função

clear all;

% 1) Obter o conjunto de treinamento.
% 2) Associar a saída desejada para cada amostra.
load x;
load y;

vX1 = x;
vYd = y;

% 3) Iniciar os vetores de pesos.
  %%Pesos da camada 1 - entrada 0 (bias) - w:coluna1
  w1(1,1) = 2 * rand - 1; %Bias N1
  
  %%Pesos da camada 1 - entrada 1 (x1) - w:coluna2
  w1(1,2) = 2 * rand - 1;

  %%Pesos da camada 2 (camada de saída)
  w2(1,1) = 2 * rand - 1; %Bias NSaída
  w2(1,2) = 2 * rand - 1;

% 4) Especificar a taxa de aprendizagem(n) , 
% precisão requerida(Emin) 
% e o número máximo de épocas (epocaMax).
n = 0.005;
epocaMax = 300;
erroMax = 0.3;

%%Treinamento Backpropagation
[w1, w2, erroTrein] = Backpropagation1N(n, epocaMax, erroMax, vX1, vYd, w1, w2);

%% Gerando gráfico do erro
t = 1:1:size(erroTrein,2)
plot(t, erroTrein(1,:), 'r');
grid;
xlabel('epoca');
ylabel('Erro Medio Quadratico - Treinamento');
figure

%%Teste MLP

%fprintf('---------------TesteMLP-----------------');

for k = 1:15
  in1 = vX1(k);
  
  yE = execMLP1N(in1, w1, w2);
  
  yEst(k) = yE;
endfor

% Gráficos dos dados de treinamento e da estimação.
plot(vX1, vYd, 'k.', vX1, yEst, 'k+');
grid;
xlabel('x');
ylabel('y : "+" = Valores Originais; "." = Valores Estimados pela MLP');