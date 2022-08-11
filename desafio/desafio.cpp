
#include <iostream>
#include <openssl/x509.h>
#include <cstdio>
#include <errno.h>
#include <openssl\applink.c>
#include <string.h>



using namespace std;


int main()
{
    FILE* fp;
    fopen_s(&fp, "certificado.der", "rt"); //abri o arquivo certificado.der
    if (fp == NULL) { //fiz um tratamento de erro caso o arquivo nao seja aberto
        cout << "\nErro ao abrir o certificado";
    }
    else {
        cout << "\nCertificado aberto\n";
    }
    X509* certificado= d2i_X509_fp(fp, NULL);  //coloco um ponteiro do tipo X509 no arquivo certificado.er
    X509_NAME * subject = X509_get_subject_name(certificado); //Pego os dados desse arquivo
    cout << certificado << endl;
    cout << subject << endl;
    char buffer[134];
    
    X509_NAME_oneline(subject, buffer, 134); //Passo os dados do arquivo convertidos para um buffer
    int i;
    for (i = 0; i < 134; i++) { //printo todo o conteudo do certificado, que foi passado para o buffer
        cout << buffer[i];
        if (buffer[i] == 47) {
            cout << endl;
        }
    }
   
}

