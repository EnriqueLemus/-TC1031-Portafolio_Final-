#include "dateTime.h"
dateTime::dateTime(){
  
}
dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  dateStruct.tm_isdst=0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
  /*if(mes=="Jun" && dia==1 && horas==22 && minutos==00 && segundos==35 ){
    std::cout<<"fechaHora "<<date<<std::endl;
  }
  if(mes=="Jun" && dia==2 && horas==5 && minutos==25 && segundos==17 ){
    std::cout<<"fechaHora "<<date<<std::endl;
  }*/
}

time_t dateTime::getDate() {
  return date;
}

bool dateTime::operator==(const dateTime &other) {
  return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
  return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
  return this->date < other.date;
}