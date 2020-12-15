struct Usr
{
    short h1;
    int h2;
};

using PUsr = Usr *;

int main()
{
    Usr u;
    PUsr pu = &u;

    pu->h1 = 10;
    pu->h2 = 20;

    u.h1 = 50;
    u.h2 = 60;
    return 0;
}
