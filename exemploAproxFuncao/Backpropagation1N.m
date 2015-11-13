function [w1, w2, erroTrein] = Backpropagation1N(n, epocaMax, erroMax, vX1, vYd, w1, w2)

    % 6) Repetição do treinamento
    for epoca = 1:epocaMax
      % 6.2) Para todas as amostras de treinamento:
      %   propagar e retropropagar.
      for k = 1:15 % 4: amostras de treinamento
        x1 = vX1(k);
        Yd = vYd(k);
        
        % 6.2.1) Propagação
        %% Camada oculta
          %--Potencial de ativação
          uN1 = w1(1,1)*1 + w1(1,2)*x1;
          
          %--Sinal de saída do neuronio 
          %   [Função de ativação sigmóide]
          yN1 = 2/(1 + exp(-2*uN1)) - 1;
        
        %% Camada de saída
          %--Potencial de ativação
          uNs = w2(1,1)*1 + w2(1,2)*yN1;
        
          %--Sinal de saída do neurônio 
          % [Função de ativação linear]
          y = uNs;
          
        % 6.2.2) Retropropagação
        %% Erro de treinamento - Camada de saída
        e = Yd - y;
        E(k) = e;
        %% Ajuste dos pesos da camada de saída
          %%--Gradiente local da camada 2 (camada de saída)
              %%-- grad2 = e * dF(linear) = e * 1 = e;
              grad2 = e;
          
          %%--Fator de ajuste dos pesos
              dw2(1,1) = n * grad2; % Atualização do peso do bias
              dw2(1,2) = n * grad2 * yN1;
          
          %%--Ajuste dos pesos
              w2(1,1) = w2(1,1) + dw2(1,1);
              w2(1,2) = w2(1,2) + dw2(1,2);
      
        %% Ajuste dos pesos da camada oculta
          %%--Gradiente local da camada 1 (camada oculta) 
              %%--- grad1 = dF(sigmoide) * sum(grad2 * pesos);
              %%--- dFSigmoide = f'() = 1 - f(x)^2
              sumGrad1 = grad2 * (w2(1,2));
              %%% Neurônio 1 da camada oculta 
                dFSigmoide1N1 = (1 - (((2 / (1 + exp(-2*uN1))) -1)^2));
              grad1N1 = sumGrad1 * dFSigmoide1N1;
      
          %%--Fator de ajuste dos pesos
              %%% Neurônio 1 da camada oculta
              dw1(1,1) = n * grad1N1;
              dw1(1,2) = n * grad1N1 * x1;
          
          %%--Ajuste dos pesos
              %%% Neurônio 1 da camada oculta
              w1(1,1) = w1(1,1) + dw1(1,1); %Bias
              w1(1,2) = w1(1,2) + dw1(1,2);

      endfor
      
      % Teste do erro médio mínimo.
      Em = (sum(sum(E.*E)))/2;
      
      if (Em < erroMax)
        break;
      endif
      
      % Imprimindo valores do treinamento
      fprintf('Epoca Treinam. = %.0f Erro Médio Quadratico = %g\n\n', epoca, Em);
      
      erroTrein(epoca) = Em;
      
    endfor
   
end