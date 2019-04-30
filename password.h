// void fill_pass_matrix_hex(void)
// {
//   int matrix[rows][cols*2], nib_0, nib_1;
//   char nibble[2];
//   for (size_t i = 0; i < rows; i++) {
//     for (size_t j = 0; j < cols*2; j=j+2) {
//     nibble[0]=password_matrix[i][(int)j/2];   //    catura character completo
//     nib_0=nibble[0];              //   lo convierte en entero para operar e imprimir
//     nib_0=nib_0>>4;               //  deja solo 4 bits mas sinificativos
//     matrix[i][j]=nib_0;
//     nibble[0]=nib_0;              //   lo convierte a caracter
// //------------------------------------------
//     nibble[1]=password_matrix[i][(int)j/2];   //    catura character completo
//     nib_1=nibble[1];          //   lo convierte en entero para imprimir
//     nib_1=nib_1 & 15;         //   solo 4 bits menos significativos
//     matrix[i][j+1]=nib_1;
//     password_matrix[i][(int)j/2] =
    
//     password_hex_matrix[rows][cols];
    
//     // matrix[i][(int)j/2]=s[nib_0*16 + nib_1];

//     }
//   }
//   for (size_t i = 0; i < rows; i++) {
//     for (size_t j = 0; j < cols*2 ; j=j+2) {
//     //   password_matrix[i][(int)j/2] = 
//       printf("%x%x  ",matrix[i][j] ,matrix[i][j+1]);
//     }
//     printf("\n");
//   }
// }

void fill_pass_matrix_hex(void) {
  int matrix[rows][cols*2], nib_0, nib_1;
  char nibble[2];
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols*2; j=j+2) {
    nibble[0]=password_matrix[i][(int)j/2];   //    catura character completo
    nib_0=nibble[0];              //   lo convierte en entero para operar e imprimir
    nib_0=nib_0>>4;               //  deja solo 4 bits mas sinificativos
    matrix[i][j]=nib_0;
    nibble[0]=nib_0;              //   lo convierte a caracter
//------------------------------------------
    nibble[1]=password_matrix[i][(int)j/2];   //    catura character completo
    nib_1=nibble[1];          //   lo convierte en entero para imprimir
    nib_1=nib_1 & 15;         //   solo 4 bits menos significativos
    matrix[i][j+1]=nib_1;
    password_hex_matrix[i][(int)j/2]=s[nib_0*16 + nib_1];

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
      printf("%c  ",password_hex_matrix[i][j] );
    }
    printf("\n");
  }
}
