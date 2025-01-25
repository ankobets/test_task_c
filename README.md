Это проект библиотеки для логирования.

Как скомпилировать и запустить

1.  Убедитесь, что у вас установлен g++ и make.
2.  Клонируйте репозиторий:

    bash
    git clone <репозиторий>
    cd logger

3. Соберите проект:

    bash
    make

4. Запустите приложение:

    bash
    ./logger <log_file> <log_level>

5. После запуска приложения, вы можете ввести одну из следующих команд:
   • w - для добавления лога в файл с уровнем важности и сообщением;
   • s - для изменения уровня важности по умолчанию;
   • e - для выхода из приложения.

6. Очистка проекта:

    bash
    make clean