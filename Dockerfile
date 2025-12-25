FROM gcc:latest

WORKDIR /app
COPY . .
RUN g++ -o wordle wordle.cpp
CMD ["./wordle"]
