// pr_c_mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Cliente.h"
#include <iostream>
using namespace  std;

int main()
{

    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit:";
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin, nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono:";
    cin >> telefono;
    cin.ignore();
    cout << "Fecha Nacimiento:";
    cin >> fecha_nacimiento;

    Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

    c.crear();
    c.leer();
    c.actualizar();
    c.eliminar();

    system("pause");
    return 0;

}

/*// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mysql.h> 
#include <string>
#include "Cliente.h"
using namespace std;
int q_estado;

void actualizar();
void eliminar();
void ingresom();
void consultam();
void actualizarm();
void eliminarm();


int main()
{
    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit: "<<endl;
    getline(cin, nit);
    cout << "Ingrese Nombres: " << endl;
    getline(cin, nombres);
    cout << "Ingrese Apellidos: " << endl;
    getline(cin, apellidos);
    cout << "Ingrese Direccion: " << endl;
    getline(cin, direccion);
    cout << "Ingrese Telefono: " << endl;
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: " << endl;
    cin >> fecha_nacimiento;
    
    Cliente c = Cliente(nombres,apellidos,direccion,telefono,fecha_nacimiento,nit);
    c.crear();
    c.leer();
        system("pause");
        return 0;
    }


void actualizar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string num,productoaux, idmarcaaux, Descripcionaux, precio_costoaux, precio_ventaaux, existenciaaux, fecha_ingresoaux = "now()";
        cout << "Ingrese ID del producto que desea actualizar: ";
        cin >> num;
        system("cls");

        cout << "Ingrese Producto: ";
        getline(cin, productoaux);
        //system("pause");
        cout << "Ingrese IDmarca: ";
        cin >> idmarcaaux;
        //system("pause");
        cout << "Ingrese Descripcion: ";
        getline(cin, Descripcionaux);
        //system("pause");
        cout << "Ingrese Precio_costo: ";
        cin >> precio_costoaux;
        cin.ignore();
        cout << "Ingrese Precio_venta: ";
        cin >> precio_ventaaux;
        //system("pause");
        cout << "Ingrese Existencias: ";
        cin >> existenciaaux;
        //system("pause");

        string actualizar = "update productos set idproducto="+num+" (producto,idmarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + productoaux + "," + idmarcaaux + "," + Descripcionaux + "," + precio_costoaux + "," + precio_ventaaux + "," + existenciaaux + "," + fecha_ingresoaux + "')";
        const char* c = actualizar.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            cout << "Actualizacion finalizada" << endl;
            }else {
            cout << "Error al actualizar" << endl;
        }


}
void eliminar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string num;
    cout << "Ingrese ID del producto que desea eliminar: ";
    cin >> num;
    system("cls");

    string eliminar = "delete from productos where idproducto=" + num + "";
    const char* c = eliminar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Eliminacion finalizada" << endl;
    }
    else {
        cout << "Error al eliminar" << endl;
    }
}



void ingresom() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string marca;
    cout << "Ingrese Marca: ";
    getline(cin, marca);
    //system("pause");
   
    string insert = "insert into marcas(marca) values ('" + marca + "')"; 
    const char* i = insert.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso Exitoso" << endl;
    }
    else {
        cout << "Error al ingresar" << endl;
    }

}

void consultam() {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string consulta = "selelct * from marcas";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "," << fila[1];
        }
    }
    else {
        cout << "Error al consultar" << endl;
    }


}

void actualizarm() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string num, marca;
    cout << "Ingrese ID de la marca que desea actualizar: ";
    cin >> num;
    system("cls");

    cout << "Ingrese Marca: ";
    getline(cin, marca);
    //system("pause");

    string actualizar = "update marcas set idmarca=" + num + " (marca) values ('" + marca + "')";
    const char* c = actualizar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Actualizacion finalizada" << endl;
    }
    else {
        cout << "Error al actualizar" << endl;
    }


}
void eliminarm() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string num;
    cout << "Ingrese ID de la marca que desea eliminar: ";
    cin >> num;
    system("cls");

    string eliminar = "delete from marcas where idmarca=" + num + "";
    const char* c = eliminar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Eliminacion finalizada" << endl;
    }
    else {
        cout << "Error al eliminar" << endl;
    }
}*/
