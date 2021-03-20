#!/bin/bash
#Script para crear archivos .c
echo "Escriba el nombre del archivo a crear:"
read document_name
if [[ ! -z $document_name ]]; then
	touch $document_name
	echo "/*" >> $document_name
	echo "Autor:" $(whoami) >> $document_name
	echo "Compilador:" $(gcc --version) >> $document_name
	echo "Escriba las instrucciones de compilación:"
	read compilado
	echo "Compilado:" $compilado >> $document_name
	echo "Fecha:" $(date) >> $document_name
	echo "Escriba las librerias (omita stdio):"
	read librerias
	echo "Librerias: stdio," $librerias >> $document_name
	echo "Escriba el resumen:"
	read resumen
	echo "Resumen:" $resumen >> $document_name
	echo "Escriba la entrada:"
	read entrada
	echo "Entrada:" $entrada >> $document_name
	echo "Escriba la salida:"
	read salida
	echo "Salida:" $salida >> $document_name
	echo "*/" >> $document_name
	echo "" >> $document_name
	echo "//Librerias" >> $document_name
	echo "#include <stdio.h>" >> $document_name
	echo "//Numerar los pasos del pseudocodigo" >> $document_name
fi
