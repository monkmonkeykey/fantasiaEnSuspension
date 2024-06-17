# Patch para Pure Data

Este patch de Pure Data utiliza varias librerías y objetos externos. A continuación, se proporcionan instrucciones para instalar las librerías necesarias para ejecutar este patch correctamente.

## Requisitos

- Pure Data (Pd) Extended o Vanilla con soporte para librerías externas
- Librerías y objetos externos:
  - cyclone
  - comport

## Instalación de Pure Data

Si aún no tienes Pure Data instalado, puedes descargarlo e instalarlo desde [aquí](https://puredata.info/downloads).

## Instalación de Librerías Externas

### 1. Cyclone

Cyclone es una librería de Pure Data que replica muchos de los objetos de Max/MSP. Para instalar Cyclone:

1. Abre Pure Data.
2. Ve a `Help -> Find Externals`.
3. En el buscador, escribe `cyclone` y haz clic en `Search`.
4. Selecciona `cyclone` en los resultados de búsqueda y haz clic en `Install`.

### 2. comport

`comport` es una librería para la comunicación serial. Para instalar comport:

1. Abre Pure Data.
2. Ve a `Help -> Find Externals`.
3. En el buscador, escribe `comport` y haz clic en `Search`.
4. Selecciona `comport` en los resultados de búsqueda y haz clic en `Install`.

## Descripción del Patch

El patch de Pure Data incluido realiza varias funciones de procesamiento de señales y comunicación serial. Aquí hay una breve descripción de los componentes principales:

- `noise~`: Genera ruido blanco.
- `hip~ 500`: Filtro pasa altos con una frecuencia de corte de 500 Hz.
- `hsl`: Control deslizante horizontal para ajustar la frecuencia de corte.
- `dac~ 1 2`: Envia la señal de audio a las salidas de audio 1 y 2.
- `comport`: Objeto para la comunicación serial configurado en el puerto 1 con una velocidad de 9600 bps.
- `cyclone/scale`, `cyclone/line~`, `cyclone/snapshot~`: Objetos de la librería Cyclone para escalado, generación de línea y toma de muestras respectivamente.

## Cómo Ejecutar el Patch

1. Abre Pure Data.
2. Abre el archivo del patch (.pd) en Pure Data.
3. Asegúrate de que todas las librerías necesarias estén instaladas.
4. Activa el procesamiento de audio haciendo clic en `DSP On` en el menú principal de Pure Data.
5. Interactúa con los controles del patch según sea necesario.

Para más información sobre el uso de Pure Data, visita la [documentación oficial](https://puredata.info/docs).

## Montar el Patch como un Servicio

Para montar el patch como un servicio en Linux, crea un archivo de servicio de systemd con el siguiente contenido:

```ini
[Unit]
Description=Patch de Pure Data
After=network.target

[Service]
User=pi
ExecStart=pd /home/pi/fantasiaEnSuspension/fantasiaEnSuspension.pd
Restart=always

[Install]
WantedBy=multi-user.target
