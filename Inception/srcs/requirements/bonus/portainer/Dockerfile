FROM alpine:3.14.2

ENV PORTAINER_VERSION=2.14.2 \
    PORTAINER_HOME=/var/lib/portainer

RUN apk update && \
    apk upgrade && \
    apk add bash bind-tools ca-certificates curl jq tar

RUN mkdir ${PORTAINER_HOME} && \
    addgroup -S portainer && \
    adduser -S -D -g "" -G portainer -s /bin/sh -h ${PORTAINER_HOME} portainer && \
    chown portainer:portainer ${PORTAINER_HOME}

RUN curl -sSL https://github.com/portainer/portainer/releases/download/${PORTAINER_VERSION}/portainer-${PORTAINER_VERSION}-linux-amd64.tar.gz | \
    tar -xzo -C /usr/local

RUN apk del tar && \
    rm -rf /var/cache/apk/*

CMD ["/usr/local/portainer/portainer"]

