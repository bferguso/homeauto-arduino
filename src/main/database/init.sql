create user homeauto password 'homeauto';
create database homeauto with owner = homeauto;
create schema homeauto;
\c homeauto
create table homeauto.ha_environment_log (
    sensor_location VARCHAR(20),
    temperature numeric(5,2),
    humidity numeric(5,2),
    pressure numeric(6,2),
    altitude numeric(5,2),
    heat_index numeric(5,2),
    sample_timestamp timestamp default current_timestamp
);

create index ha_env_log_location_idx on ha_environment_log(sensor_location NULLS FIRST);
create index ha_env_log_sample_time_idx on ha_environment_log(sample_timestamp NULLS FIRST);

insert into ha_environment_log(sensor_location, temperature, humidity, pressure, altitude)
VALUES ('wishful',28.3, 94.89, 1013.11, 0.01);