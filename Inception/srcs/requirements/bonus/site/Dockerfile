FROM  alpine:3.12.0

RUN apk update; \
    apk add --update nodejs npm

COPY ./conf /

CMD ["node", "run.js"]
