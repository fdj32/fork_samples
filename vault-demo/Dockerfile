# Build Front End React Project
FROM node:alpine3.13 as buildReact
WORKDIR /app
COPY react-vault-demo/package.json /app
ENV PATH /app/node_modules/.bin:$PATH
RUN npm install --silent
COPY react-vault-demo/public /app/public
COPY react-vault-demo/src /app/src
RUN npm run-script build

# Build Back End Java Project
FROM gradle:jdk8-hotspot as buildJava
WORKDIR /app
COPY java-vault-demo/settings.gradle /app
COPY java-vault-demo/build.gradle /app
COPY java-vault-demo/src /app/src
COPY --from=buildReact /app/build /app/src/main/resources/static/
RUN gradle bootJar

# Start App
FROM openjdk:8-alpine as runJava
COPY --from=buildJava /app/build/libs/java-vault-demo-1.1.0.jar app.jar
EXPOSE 8080
ENTRYPOINT ["java", "-jar", "app.jar"]

# docker build -t vault_demo .
# docker run --name=vault_demo -p 8080:8080 vault_demo
# docker container stop vault_demo
# docker container rm vault_demo

# docker run --cap-add=IPC_LOCK -d --name=dev_vault -p 8200:8200 vault
# docker container stop dev_vault
# docker container rm dev_vault
# docker logs dev_vault
# Unseal Key: oF3aLSaiM3WAusTm/zSevHvgC84YV/ReYNi0IeTlnMw=
# Root Token: s.3OfQ0FlooukDuL46DkL6J7qa
# application.yml spring.cloud.vault.token