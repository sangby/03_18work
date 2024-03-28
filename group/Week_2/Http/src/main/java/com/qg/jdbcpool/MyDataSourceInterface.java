package com.qg.jdbcpool;

import javax.sql.DataSource;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.SQLFeatureNotSupportedException;
import java.util.logging.Logger;

public interface MyDataSourceInterface extends DataSource {
    @Override
    Connection getConnection() throws SQLException;

    @Override
    Connection getConnection(String username, String password) throws SQLException;

    @Override
    default <T> T unwrap(Class<T> iface) throws SQLException {
        return null;
    }

//以下是默认方法,不必重写
    @Override
    default boolean isWrapperFor(Class<?> iface) throws SQLException {
        return false;
    }

    @Override
    default PrintWriter getLogWriter() throws SQLException {
        return null;
    }

    @Override
    default void setLogWriter(PrintWriter out) throws SQLException {

    }

    @Override
    default void setLoginTimeout(int seconds) throws SQLException {

    }

    @Override
    default int getLoginTimeout() throws SQLException {
        return 0;
    }

    @Override
    default Logger getParentLogger() throws SQLFeatureNotSupportedException {
        return null;
    }
}
