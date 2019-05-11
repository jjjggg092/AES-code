//---------------------------------------------------------------------------

//          Matrix operations routines
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void print_state_matrix(void)
{
 int i,j;

        for(i=0;i<rows;i++)    // matrix [fila][column]
            {
            cout<<endl;
            for (j=0;j<cols;j++)
                {
                  printf("%x ",state_matrix[i][j]);
                //  cout<<" " <<state_matrix[i][j];  // mantiene fija la fila y barre las columnas
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
                 printf("%x ",password_matrix[i][j]);
                //  cout<<" " <<password_matrix[i][j];  // mantiene fija la fila y barre las columnas
                }
                    // cout<<endl;

            }
        cout<<endl<<"---------"<<endl;
}
//-----------------------------------------------------------------
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




void SubBytes(void) {
  unsigned char matrix[rows][cols*2], nib_0, nib_1;
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
    state_matrix[i][(int)j/2]=inv_s[nib_0*16 + nib_1];
    }
  }
  cout <<"no se algo"<<endl;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols*2 ; j=j+2) {
      //state_matrix[i][(int)j/2]=s[nib_0*16 + nib_1];
      printf("%x%x  ",matrix[i][j] ,matrix[i][j+1]);
    }
    printf("\n");
  }
  printf("------------------\n");
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols ; j++) {
      printf("%x  ",state_matrix[i][j] );
    }
    printf("\n");
  }
}

void ShiftRows(void) {
  int aux1, aux2, arr[4];;

  aux1= state_matrix[1][0];
  printf("Shift Rows:\n");
  for (size_t i = 0; i < 3; i++)
    state_matrix[1][i]=state_matrix[1][i+1];
  state_matrix[1][3]=aux1;

  aux1= state_matrix[2][0];
  aux2= state_matrix[2][1];
  for (size_t i = 0; i < 2; i++)
    state_matrix[2][i]=state_matrix[2][i+2];
  state_matrix[2][2]=aux1;
  state_matrix[2][3]=aux2;

  for (size_t i = 0; i < 4; i++) arr[i]=state_matrix[3][i];
  for (size_t i = 0; i < 3; i++)
    state_matrix[3][i+1]=arr[i];
  state_matrix[3][0]=arr[3];

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols ; j++) {
      printf("%x  ",state_matrix[i][j] );
    }
    printf("\n");
  }
}


void matrixToArray(void){
      int k = 0;
      printf("AQUI");
      for(int i = 0; i<rows ; i++)
          for(int j = 0; j<cols; j++){
              state[k] = state_matrix[j][i];
              printf("%x ",state[k]);

              //printf("%x ", state_matrix[i][j]);
              k++;
  }
  }


  void MixColumns(void) {
	unsigned char tmp[16];


  	tmp[0] = (unsigned char)mul14[state[0]] ^ mul11[state[1]] ^ mul13[state[2]] ^ mul9[state[3]];
  	tmp[1] = (unsigned char)mul9[state[0]] ^ mul14[state[1]] ^ mul11[state[2]] ^ mul13[state[3]];
  	tmp[2] = (unsigned char)mul13[state[0]] ^ mul9[state[1]] ^ mul14[state[2]] ^ mul11[state[3]];
  	tmp[3] = (unsigned char)mul11[state[0]] ^ mul13[state[1]] ^ mul9[state[2]] ^ mul14[state[3]];

  	tmp[4] = (unsigned char)mul14[state[4]] ^ mul11[state[5]] ^ mul13[state[6]] ^ mul9[state[7]];
  	tmp[5] = (unsigned char)mul9[state[4]] ^ mul14[state[5]] ^ mul11[state[6]] ^ mul13[state[7]];
  	tmp[6] = (unsigned char)mul13[state[4]] ^ mul9[state[5]] ^ mul14[state[6]] ^ mul11[state[7]];
  	tmp[7] = (unsigned char)mul11[state[4]] ^ mul13[state[5]] ^ mul9[state[6]] ^ mul14[state[7]];

  	tmp[8] = (unsigned char)mul14[state[8]] ^ mul11[state[9]] ^ mul13[state[10]] ^ mul9[state[11]];
  	tmp[9] = (unsigned char)mul9[state[8]] ^ mul14[state[9]] ^ mul11[state[10]] ^ mul13[state[11]];
  	tmp[10] = (unsigned char)mul13[state[8]] ^ mul9[state[9]] ^ mul14[state[10]] ^ mul11[state[11]];
  	tmp[11] = (unsigned char)mul11[state[8]] ^ mul13[state[9]] ^ mul9[state[10]] ^ mul14[state[11]];

  	tmp[12] = (unsigned char)mul14[state[12]] ^ mul11[state[13]] ^ mul13[state[14]] ^ mul9[state[15]];
  	tmp[13] = (unsigned char)mul9[state[12]] ^ mul14[state[13]] ^ mul11[state[14]] ^ mul13[state[15]];
  	tmp[14] = (unsigned char)mul13[state[12]] ^ mul9[state[13]] ^ mul14[state[14]] ^ mul11[state[15]];
    tmp[15] = (unsigned char)mul11[state[12]] ^ mul13[state[13]] ^ mul9[state[14]] ^ mul14[state[15]];

	for (int i = 0; i < 16; i++) {
		state[i] = tmp[i];
	}

    puts("MixColums: ");
    for(int i = 0; i<16;i++){
        printf("%x ", state_matrix[i]);}
}

void AddRoundKey()
{
  int k=0;

  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      state_matrix[j][i] = state[k] ^ password_matrix[j][i];
      k++;   }
}
void F_AddRoundKey()
{
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
      state_matrix[i][j] = state_matrix[i][j] ^ password_matrix[i][j];
}
