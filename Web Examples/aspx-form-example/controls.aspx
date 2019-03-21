<!--controls.aspx
    Kyle Mason
    Assignment #9 -->

<%@ Page Language="C#" AutoEventWireup="true" CodeFile="controls.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <p>
            Name:
            <asp:TextBox ID="name" runat="server"></asp:TextBox>
            <br />
            Address:
            <asp:TextBox ID="address" runat="server"></asp:TextBox>
            Favorite color
            <asp:DropDownList ID="color" runat="server">
                <asp:ListItem Selected="True" Value="Yellow">Yellow</asp:ListItem>
                <asp:ListItem Value="Red">Red</asp:ListItem>
                <asp:ListItem Value="Blue">Blue</asp:ListItem>
            </asp:DropDownList>
            <br />
            Favorite catergory of music:
            <asp:DropDownList ID="music" runat="server">
                <asp:ListItem Selected="True" Value="classical">classical</asp:ListItem>
                <asp:ListItem Value="jazz">jazz</asp:ListItem>
                <asp:ListItem Value="rock">rock</asp:ListItem>
            </asp:DropDownList>
            <br />
            <asp:Button ID="submit" runat="server" Text="Submit" />
            <br />

            <%if (IsPostBack) {%>
                Hi <%=name.Text %>;
                your favorite color is <%=color.SelectedValue %><br />
                Hello <%= name.Text %>;
                your favorite category of music is <%=music.SelectedValue %>
            <%} %>

        </p>
    </div>
    </form>
</body>
</html>
