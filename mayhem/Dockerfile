FROM --platform=linux/amd64 ubuntu:23.04 as builder
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libz-dev
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang cmake make


ADD . /MaskedVByte
WORKDIR /MaskedVByte
RUN make

FROM --platform=linux/amd64 ubuntu:23.04

COPY --from=builder /MaskedVByte /

# WORKDIR /MaskedVByte /

RUN /unit



# RUN ls

# RUN ./unit

