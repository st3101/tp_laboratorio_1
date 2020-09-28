float suma(float n1,float n2)
{
    float resultado=n1+n2;
    return resultado;
}
float resta(float n1,float n2)
{
    float resultado=n1-n2;
    return resultado;
}
float division(float n1,float n2)
{
    float resultado=n1/n2;
    return resultado;
}
float multiplicacion(float n1, float n2)
{
    float resultado=n1*n2;
    return resultado;
}
float factorialN2(float n1)
{
    int i;
    long int resultado;

    resultado=1;

    for(i=1;i<=n1;i++)
    {
        resultado=resultado*i;
    }
    return resultado;
}


float factorialN1(float n2)
{
    int i;
    long int resultado;

    resultado=1;

    for(i=1;i<=n2;i++)
    {
        resultado=resultado*i;
    }
    return resultado;
}
