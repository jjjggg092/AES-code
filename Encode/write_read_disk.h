//---------------------------------------------------------------------------
int read_text(void)
{
    int j;
    FILE *in_file;


    if ((in_file = fopen ("texto.txt", "rt")) == NULL)
		printf("File no existe");
	else
	{
		fseek(in_file, 0, SEEK_SET);
        fscanf(in_file,"%[^\n]s",plaintext);

    }
    fclose(in_file);

}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------

int write_text(int size_text)
{
    int j;
    FILE *out_file;
    if ((out_file = fopen ("texto_ciph.txt", "wt")) == NULL)
        //if ((out_file = fopen ("texto.txt", "t")) == NULL)
		printf("File no existe");
	else
	{
		fseek(out_file, 0, SEEK_SET);
    for (size_t i = 0; i < size_text; i++) {
      for(j=0;j<size_text;j++)
      {
       fprintf(out_file, "%c", state_matrix[j][i]);
       //printf("%c",msg_w[j]);
      }
    }

    }

    fclose(out_file);

}
//-----------------------------------------------------------------
