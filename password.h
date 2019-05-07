void fill_pass_matrix_hex(void) {
  int matrix[4][2], nib_0, nib_1;
  char nibble[2];
  int rot_word[4];

  rot_word[0] = password_matrix[1][3];  
  rot_word[1] = password_matrix[2][3];  
  rot_word[2] = password_matrix[3][3];  
  rot_word[3] = password_matrix[0][3];


  printf("------------------\n");
  for (size_t i = 0; i < rows; i++) {
      printf("%c  ",rot_word[i]);
    }
    printf("\n");

    for(int i=0;i<4;i++)
    {
        nibble[0]=rot_word[i];   //    catura character completo
        nib_0=nibble[0];              //   lo convierte en entero para operar e imprimir
        nib_0=nib_0>>4;               //  deja solo 4 bits mas sinificativos
        matrix[i][0]=nib_0;
        nibble[0]=nib_0;              //   lo convierte a caracter
        nibble[1]=rot_word[i];   //    catura character completo
        nib_1=nibble[1];          //   lo convierte en entero para imprimir
        nib_1=nib_1 & 15;         //   solo 4 bits menos significativos
        matrix[i][1] = nib_1;
        rot_word[i] = s[nib_0*16 + nib_1];
    }  

  printf("------------------\n");
  for (size_t i = 0; i < rows; i++) {
      printf("%x  ",rot_word[i]);
    }
    printf("\n");

    //   printf("%d\n  ",int(password_matrix[0][0]));
    //   printf("%x \n ",int(rcon[0][0]));

    for(int i=0;i<4;i++)
    {
        rot_word[i] = char(rot_word[i])^char(password_matrix[i][0])^char(rcon[i][count_rcon]);  //digamos que funciona
        password_matrix[i][0] = char(rot_word[i]);
        // printf("%x\n", rot_word[i]);
    }
    count_rcon++;
    

}

void xor_key_schedule(void)
{
    for(int i=1;i<4;i++)
        for(int j=0;j<4;j++)
    {   
        password_matrix[j][i] = char(password_matrix[j][i])^char(password_matrix[j][i-1]); 
    }
}

