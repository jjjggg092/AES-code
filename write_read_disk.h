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

int write_text(char msg_w[], int size_text)
{
    int j;
    FILE *out_file;
    if ((out_file = fopen ("texto_ciph.txt", "wt")) == NULL)
        //if ((out_file = fopen ("texto.txt", "t")) == NULL)
		printf("File no existe");
	else
	{
		fseek(out_file, 0, SEEK_SET);
        for(j=0;j<size_text;j++)
        {
         fprintf(out_file, "%c", msg_w[j]);
         //printf("%c",msg_w[j]);
        }   
        
    }
    
    fclose(out_file);
    
}
//-----------------------------------------------------------------