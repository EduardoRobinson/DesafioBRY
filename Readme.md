Relatorio questão 1:
Parte 1:
-Primeiro criei um certificado x509 seguindo o tutorial desse video:https://www.youtube.com/watch?v=qoS4bLmstlk&list=LL&index=6&t=434s
-Criei uma serverkey 2048 usando o comando:sudo openssl genrsa -out privkey.pem 2048
-Depois criei o certificado usando o comando:sudo openssl req -new -x509 -days 3650 -nodes -key privkey.pem -sha256 -out certicado.pem
-E apos isso coloquei os seguintes dados no certificado:
C=BR ---Pais
ST=Sao Paulo --Provincia
L=Tatui --Cidade
O=github.com/EduardoRobinson --Meu site do github
OU=BRY Tecnologia --Organização
CN=BRY 
emailAddress=eduardorobinson@alunos.utfpr.edu.br --Email de contato
-Gerando o certificado.pem(vou converter ele para o formato DER ao decorrer do desenvolvimento)
-Apos isso criei um arquivo de configuração do servidor, gerando o server.csr.cnf.
-E apos isso juntei o certificado a key 2048 que havia criado anteriormente usando o comando:sudo openssl req -new -nodes -out server.csr -keyout server.key -config server.csr.cnf
-Então criei um arquivo de extensão do servidor, colocando como DNS meu github:gitbub.com/EduardoRobinson
-E por fim criei o certificado do servidor usando o comando: sudo openssl x509 -req -in server.csr -CA certificado.pem -CAkey privkey.pem -CAcreateserial -out server.crt -days 3650 -extfile server_v3.ext
-E por fim converti o certificado.dem em um certicado.der usando o comando:openssl x509 -in certificado.pem -out certificado.der -outform DER
Parte 2:
-Como plataforma para o desenvolvimento escolhi o visual studio community 2022, pois consigo linkar o programa c++ e seu compilador a biblioteca OPENSLL.
-Comentei todo o codigo para ficar mais claro minha ideia.
