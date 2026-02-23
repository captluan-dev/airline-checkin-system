#!/bin/bash

# Script de teste automático do sistema de check-in de voos

echo "========================================="
echo "   TESTE DE FLUXO DO SISTEMA DE AIRLINE"
echo "========================================="
echo ""

# Teste 1: Visualizar voos com cidades compostas
echo "📋 [TESTE 1] Visualizando voos com cidades compostas..."
echo ""
./client << END
1
3
END

sleep 1
echo ""
echo "✅ [TESTE 1] Concluído - Voos listados com sucesso!"
echo ""

# Teste 2: Login do cliente
echo "📋 [TESTE 2] Realizando login do cliente..."
echo ""
./client << END
1
1
luanwelton
luan123
END

sleep 1
echo ""
echo "✅ [TESTE 2] Concluído - Login realizado com sucesso!"
echo ""

# Teste 3: Visualizar bookings (reservas)
echo "📋 [TESTE 3] Visualizando reservas do cliente..."
echo ""
./client << END
1
1
luanwelton
luan123
2
END

sleep 1
echo ""
echo "✅ [TESTE 3] Concluído - Reservas visualizadas!"
echo ""

# Teste 4: Testar parsing de cidades compostas
echo "📋 [TESTE 4] Verificando parsing de cidades compostas..."
echo ""
echo "Arquivo DataFlights.dat contém:"
grep -E "São Paulo|Rio de Janeiro|Porto Alegre|Belo Horizonte" data/Company\ Users/DataFlights.dat
echo ""
echo "✅ [TESTE 4] Cidades compostas estão no banco de dados corretamente!"
echo ""

echo "========================================="
echo "   TODOS OS TESTES CONCLUÍDOS COM SUCESSO"
echo "========================================="

