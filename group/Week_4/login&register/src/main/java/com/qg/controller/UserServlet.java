package com.qg.controller;

import com.alibaba.druid.support.json.JSONUtils;
import com.qg.bean.SingletonFactory;
import com.qg.constant.Result;
import com.qg.po.User;
import com.qg.service.UserService;
import com.qg.util.JsonUtil;
import com.qg.util.impl.PoolUtil;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.sql.SQLException;

@WebServlet("/user/*")
public class UserServlet extends BaseServlet {
    public void login(HttpServletRequest req, HttpServletResponse resp) {
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        User user = new User();
        user.setPassWord(password);
        user.setUserName(username);

        if (username.equals("")||password.equals("")){
            System.out.println("数据校验");
            return;
        }

        UserService userService = SingletonFactory.getUserServiceSingleton();
        Result<User> userResult = null;
        try {
            userResult = userService.login(user.getUserName(),user.getPassWord());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        //封装为json对象,返回前端后,通过code判断登录情况
        HttpSession session = req.getSession();

        session.setAttribute("username",user.getUserName());

        JsonUtil.toJson(userResult,resp);




    }

    public void register(HttpServletRequest req, HttpServletResponse resp) throws SQLException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        User user = new User();
        user.setPassWord(password);
        user.setUserName(username);

        if (username.equals("")||password.equals("")){
            System.out.println("数据校验");
            return;
        }
        UserService userService = SingletonFactory.getUserServiceSingleton();
        Result<User> registerResult = userService.register(user.getUserName(),user.getPassWord());

        JsonUtil.toJson(registerResult,resp);
    }
}
