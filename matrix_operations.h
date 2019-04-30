//---------------------------------------------------------------------------

//          Matrix operations routines
//---------------------------------------------------------------------------
void print_aux_matrix(void)
{
 int i,j;

        for(i=0;i<rows;i++)    // matrix [fila][column]
            {
            cout<<endl;
            for (j=0;j<cols;j++)
                {
                 cout<<" " <<aux_matrix[i][j];  // mantiene fija la fila y barre las columnas
                }
            }
        cout<<endl<<"---------"<<endl;
}
//---------------------------------------------------------------------------
void print_state_matrix(void)
{
 int i,j;

        for(i=0;i<rows;i++)    // matrix [fila][column]
            {
            cout<<endl;
            for (j=0;j<cols;j++)
                {
                 cout<<" " <<state_matrix[i][j];  // mantiene fija la fila y barre las columnas
                }
            }
        cout<<endl<<"---------"<<endl;
}
//-----------------------------------------------------------------
void print_password_matrix(void)
{
 int i,j;

        for(i=0;i<rows;i++)    // matrix [fila][column]
            {
            cout<<endl;
            for (j=0;j<cols;j++)
                {
                 cout<<" " <<password_matrix[i][j];  // mantiene fija la fila y barre las columnas
                }
            }
        cout<<endl<<"---------"<<endl;
}
//-----------------------------------------------------------------
void print_chipher_matrix(void)
{
 int i,j;

        for(i=0;i<rows;i++)    // matrix [fila][column]
            {
            cout<<endl;
            for (j=0;j<cols;j++)
                {
                 cout<<" " <<chipher_matrix[i][j];  // mantiene fija la fila y barre las columnas
                }
            }
        cout<<endl<<"---------"<<endl;
}
//-----------------------------------------------------------------
void fill_password_matrix(void)
{
 int i,j, filler_count=0, counter=0;

    for (i=0; i<cols;i++)   // matrix [fila][column]
    {
        for (j=0; j<rows;j++)     // filas
        {
          if(counter<password_lenght-1) password_matrix[j][i]= password[counter];
          else {password_matrix[j][i]=hex_number[filler_count]; filler_count++;}
          counter++;
        }
    }
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
void fill_state_matrix(void)
{
 int i,j,counter=0;

    for (i=0; i<cols;i++)   // matrix [fila][column]
    {
        for (j=0; j<rows;j++)     // filas
        {
          state_matrix[j][i]= plaintext[counter];  // mantiene la columna [i] y  mueve la fila [j]
          counter++;
        }
    }
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
void fill_chipher_matrix(void) {
  for (size_t i = 0; i < cols ; i++) {
    for (size_t j = 0; j < rows ; j++) {
      chipher_matrix[j][i]= password_matrix[j][i]^state_matrix[j][i];
    }
  }
}

void fill_chipher_matrix_round(void) {
  for (size_t i = 0; i < cols ; i++) {
    for (size_t j = 0; j < rows ; j++) {
      chipher_matrix[j][i]= password_matrix[j][i]^chipher_matrix[j][i];
    }
  }
}

void fill_de_chipher_matrix_round(void){

  for (size_t i = 0; i < cols ; i++) {
    for (size_t j = 0; j < rows ; j++) {
      aux_matrix[j][i]= password_matrix[j][i]^aux_matrix[j][i];
    }
  }
}


//-----------------------------------------------------------------
void rotate_password_matrix(void) {
  char aux;
  char aux1[rows][cols];
  for (size_t i = 0; i < cols ; i++) {
    for (size_t j = 0; j < rows; j++) {
      aux1[j][i]=password_matrix[j][i];
    }
  }
for (size_t k = 0; k < cols; k++) {
  aux= password_matrix[3][k];
  for (size_t i = 1; i < rows; i++) {
    password_matrix[i][k]=aux1[i-1][k];
  }
  password_matrix[0][k]=aux;
}
}
void rotate_password_matrix_to_decrypt(void) {
  char aux;
  char aux1[rows][cols];
  for (size_t i = 0; i < cols ; i++) {
    for (size_t j = 0; j < rows; j++) {
      aux1[j][i]=password_matrix[j][i];
    }
  }
  for (size_t k = 0; k < cols; k++) {
    aux= password_matrix[0][k];
    for (size_t i = 1; i < rows; i++) {
      password_matrix[i-1][k]=aux1[i][k];
    }
    password_matrix[3][k]=aux;
  }
}



//----------------------------------------------------------------
//-----------------------------------------
void cypher_pass_plain_text(void)
{
 int i,x,y,j=0;

//    for(i=0;i<strlen(password);i++)
   for(i=0;i<strlen(plaintext);i++)
    {
        ciphertext[i] = plaintext[i]^password[j];    //plaintext[i+3];
        j++;
        if(j==strlen(password)) j=0;
    }
}
//-----------------------------------------
void decypher_pass_text(void)
{
 int i,x,y,j=0;

//    for(i=0;i<strlen(password);i++)
   for(i=0;i<strlen(plaintext);i++)

    {
        deciphertext[i] = ciphertext[i]^password[j];    //plaintext[i+3];
        j++;
        if(j==strlen(password)) j=0;

    }
}
//------------------------------------------
//-----------------------------------------------------------------




void SubBytes(void) {
  int matrix[rows][cols*2], nib_0, nib_1;
  char nibble[2];
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols*2; j=j+2) {
    nibble[0]=state_matrix[i][(int)j/2];   //    catura character completo
    nib_0=nibble[0];              //   lo convierte en entero para operar e imprimir
    nib_0=nib_0>>4;               //  deja solo 4 bits mas sinificativos
    matrix[i][j]=nib_0;
    nibble[0]=nib_0;              //   lo convierte a caracter
//------------------------------------------
    nibble[1]=state_matrix[i][(int)j/2];   //    catura character completo
    nib_1=nibble[1];          //   lo convierte en entero para imprimir
    nib_1=nib_1 & 15;         //   solo 4 bits menos significativos
    matrix[i][j+1]=nib_1;
    state_hex_matrix[i][(int)j/2]=s[nib_0*16 + nib_1];
    }
  }
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols*2 ; j=j+2) {
      //state_hex_matrix[i][(int)j/2]=s[nib_0*16 + nib_1];
      printf("%x%x  ",matrix[i][j] ,matrix[i][j+1]);
    }
    printf("\n");
  }
  printf("------------------\n");
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols ; j++) {
      printf("%c  ",state_hex_matrix[i][j] );
    }
    printf("\n");
  }
}

void ShiftRows(void) {
  int aux1, aux2, arr[4];;

  aux1= state_hex_matrix[1][0];
  printf("Shift Rows:\n");
  for (size_t i = 0; i < 3; i++)
    state_hex_matrix[1][i]=state_hex_matrix[1][i+1];
  state_hex_matrix[1][3]=aux1;

  aux1= state_hex_matrix[2][0];
  aux2= state_hex_matrix[2][1];
  for (size_t i = 0; i < 2; i++)
    state_hex_matrix[2][i]=state_hex_matrix[2][i+2];
  state_hex_matrix[2][2]=aux1;
  state_hex_matrix[2][3]=aux2;

  for (size_t i = 0; i < 4; i++) arr[i]=state_hex_matrix[3][i];
  for (size_t i = 0; i < 3; i++)
    state_hex_matrix[3][i+1]=arr[i];
  state_hex_matrix[3][0]=arr[3];

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols ; j++) {
      printf("%x  ",state_hex_matrix[i][j] );
    }
    printf("\n");
  }
}


  void ModuloMultiplication(int vector[4]) {
    //codigo de la multiplicacion mod 16
  }

  void MixColumns(void) {
    int arr[4];
    for (size_t j = 0; j < 4; j++) {
      for (size_t i = 0; i < 4; i++) {
        arr[i]=state_hex_matrix[i][j];
      }
      ModuloMultiplication(arr);
    }

  }
